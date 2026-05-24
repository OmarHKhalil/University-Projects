import os
import cv2
import glob
import json
import torch
import random
import numpy as np
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt
from tqdm import tqdm
from torchvision import transforms, models
from torch.utils.data import Dataset, DataLoader
from skimage.metrics import peak_signal_noise_ratio as psnr
from skimage.metrics import structural_similarity as ssim

# ======================================
# GLOBAL CONFIGURATION PARAMETERS
# ======================================
# USE_RGB: 0=grayscale (1 channel), 1=RGB (3 channels)
USE_RGB = 0

# Dataset paths - assumes GoPro dataset structure
DATASET_PATH = "DBlur/Gopro"
TRAIN_BLUR_PATH = DATASET_PATH + "/train/blur"
TRAIN_SHARP_PATH = DATASET_PATH + "/train/sharp"
TEST_BLUR_PATH = DATASET_PATH + "/test/blur"
TEST_SHARP_PATH = DATASET_PATH + "/test/sharp"

# Image processing parameters
IMAGE_SIZE = 256  # All images resized to 256×256 for uniform batch processing

# Training hyperparameters
BATCH_SIZE = 16  # Number of image pairs per batch
EPOCHS = 200  # Total training iterations over entire dataset

# Loss function weights - these balance different objectives
L1_LOSS_WEIGHT = 100  # Weight for pixel-wise reconstruction loss
PERCEPTUAL_WEIGHT = 1.0  # Weight for perceptual (VGG feature) loss
GAN_WEIGHT = 0.01  # Weight for adversarial loss (kept small to prevent mode collapse)
#هي اذا عدلنا عل داتا
# Data augmentation flag
AUGMENTATION = True

# Output directory for all generated files
OUTPUT_DIR = "outputs LR"
os.makedirs(OUTPUT_DIR, exist_ok=True)

# Hardware configuration
DEVICE = "cuda" if torch.cuda.is_available() else "cpu"

# Derived parameters
CHANNELS = 3 if USE_RGB == 1 else 1
MODE_NAME = "RGB" if USE_RGB == 1 else "GRAYSCALE"

# Reproducibility seeds
torch.manual_seed(42)
np.random.seed(42)


# ======================================
# VISUAL INSPECTION UTILITY تشيك الداتا اذا صح
# ======================================
def save_visual_samples(images_a, images_b, out_path, mode="gray"):
    """
    Creates a 2-row visualization grid comparing blur/sharp image pairs.

    Technical details:
    - Row 1: Blurred input images
    - Row 2: Corresponding sharp ground truth images
    - Saves as PNG for quality inspection before training

    Args:
        images_a: List of numpy arrays (blurred images)
        images_b: List of numpy arrays (sharp images)
        out_path: File path to save the visualization
        mode: Colormap mode ('gray' for grayscale, None for RGB)
    """
    plt.figure(figsize=(10, 4))
    for i in range(min(5, len(images_a))):
        # Top row: blurred images
        plt.subplot(2, 5, i + 1)
        plt.title(f"BLUR-{i}")
        plt.imshow(images_a[i], cmap=mode)
        plt.axis("off")

        # Bottom row: sharp images
        plt.subplot(2, 5, i + 6)
        plt.title(f"SHARP-{i}")
        plt.imshow(images_b[i], cmap=mode)
        plt.axis("off")

    plt.tight_layout()
    plt.savefig(out_path)
    plt.close()


# ======================================
# CUSTOM DATASET CLASS
# ======================================
class GoProDataset(Dataset):
    """
    PyTorch Dataset for GoPro deblurring dataset.

    Technical workflow:
    1. Loads image paths at initialization (lazy loading)
    2. Reads and preprocesses images on-the-fly during training
    3. Applies optional data augmentation for regularization
    4. Normalizes to [-1, 1] range for stable GAN training
    """

    def __init__(self, blurs, sharps, augment=False):
        """
        Args:
            blurs: List of file paths to blurred images
            sharps: List of file paths to sharp images
            augment: Boolean flag for data augmentation
        """
        self.blur_images = blurs
        self.sharp_images = sharps
        self.augment = augment

        # Transformation pipeline:
        # 1. ToTensor: Converts numpy array [H,W,C] to tensor [C,H,W] and scales [0,255] → [0,1]
        # 2. Normalize: Shifts [0,1] → [-1,1] using mean=0.5, std=0.5
        #    Formula: output = (input - 0.5) / 0.5 = 2*input - 1
        tfs_list = [transforms.ToTensor(), transforms.Normalize((0.5,), (0.5,))]
        self.transform = transforms.Compose(tfs_list)

    def __len__(self):
        """Returns dataset size for DataLoader iteration"""
        return len(self.blur_images)

    def __getitem__(self, idx):
        """
        Loads and preprocesses a single image pair.

        Technical steps:
        1. Load images using OpenCV (BGR format)
        2. Convert color space based on USE_RGB flag
        3. Resize to uniform dimensions for batch processing
        4. Apply stochastic augmentation (if enabled)
        5. Normalize to [-1, 1] range
        """
        # OpenCV loads in BGR format
        blur = cv2.imread(self.blur_images[idx])
        sharp = cv2.imread(self.sharp_images[idx])

        # Color space conversion
        if USE_RGB == 1:
            # BGR → RGB for color images
            blur = cv2.cvtColor(blur, cv2.COLOR_BGR2RGB)
            sharp = cv2.cvtColor(sharp, cv2.COLOR_BGR2RGB)
        else:
            # BGR → Grayscale (single channel)
            blur = cv2.cvtColor(blur, cv2.COLOR_BGR2GRAY)
            sharp = cv2.cvtColor(sharp, cv2.COLOR_BGR2GRAY)
            # Add channel dimension: [H,W] → [H,W,1]
            blur = np.expand_dims(blur, axis=2)
            sharp = np.expand_dims(sharp, axis=2)

        # Resize to uniform dimensions (required for batch processing)
        blur = cv2.resize(blur, (IMAGE_SIZE, IMAGE_SIZE))
        sharp = cv2.resize(sharp, (IMAGE_SIZE, IMAGE_SIZE))

        # Data augmentation for regularization
        if self.augment:
            # Horizontal flip (50% probability)
            if random.random() > 0.5:
                blur = np.fliplr(blur)
                sharp = np.fliplr(sharp)

            # Vertical flip (50% probability)
            if random.random() > 0.5:
                blur = np.flipud(blur)
                sharp = np.flipud(sharp)

            # Random 90-degree rotation (30% probability)
            if random.random() > 0.7:
                k = random.choice([0, 1, 2, 3])  # 0, 90, 180, 270 degrees
                blur = np.rot90(blur, k)
                sharp = np.rot90(sharp, k)

        # Ensure contiguous memory layout (required after augmentation operations)
        blur = blur.copy()
        sharp = sharp.copy()

        # Apply normalization: [0, 255] → [-1, 1]
        blur = self.transform(blur)
        sharp = self.transform(sharp)

        return blur, sharp


# ======================================
# RESIDUAL BLOCK ARCHITECTURE
# ======================================
class ResidualBlock(nn.Module):
    """
    Residual learning block based on ResNet architecture.

    Technical design:
    - Uses skip connections to enable gradient flow
    - Formula: output = F(x) + x, where F is the residual function
    - Helps train very deep networks by mitigating vanishing gradients
    - BatchNorm stabilizes training by normalizing intermediate activations
    """

    def __init__(self, channels):
        super().__init__()
        # First convolution: maintains spatial dimensions (kernel=3, stride=1, padding=1)
        self.conv1 = nn.Conv2d(channels, channels, 3, 1, 1)
        self.bn1 = nn.BatchNorm2d(channels)
        self.relu = nn.ReLU(inplace=True)  # inplace=True saves memory

        # Second convolution
        self.conv2 = nn.Conv2d(channels, channels, 3, 1, 1)
        self.bn2 = nn.BatchNorm2d(channels)

    def forward(self, x):
        """
        Forward pass with skip connection.

        Mathematical flow:
        1. residual = x (store input)
        2. out = ReLU(BN(Conv1(x)))
        3. out = BN(Conv2(out))
        4. out = out + residual (skip connection)
        5. out = ReLU(out)
        """
        residual = x
        out = self.relu(self.bn1(self.conv1(x)))
        out = self.bn2(self.conv2(out))
        out += residual  # Skip connection enables gradient flow
        return self.relu(out)


# ======================================
# U-NET GENERATOR WITH SKIP CONNECTIONS
# ======================================
class ImprovedUNetGenerator(nn.Module):
    """
    U-Net architecture generator for image-to-image translation.

    Architecture overview:
    - Encoder: 4 downsampling blocks (256→128→64→32→16)
    - Bottleneck: 3 residual blocks at lowest resolution
    - Decoder: 4 upsampling blocks with skip connections
    - Skip connections: concatenate encoder features with decoder features

    Technical benefits:
    - Multi-scale feature learning
    - Preserves spatial information through skip connections
    - Residual bottleneck prevents information loss
    """

    def __init__(self):
        super().__init__()

        # ENCODER (Downsampling path)
        # Each block: Conv2d(in, out, kernel=4, stride=2, padding=1)
        # Stride=2 halves spatial dimensions: H×W → H/2×W/2

        # enc1: 256×256×1 → 128×128×64
        self.enc1 = nn.Sequential(
            nn.Conv2d(CHANNELS, 64, 4, 2, 1),
            nn.BatchNorm2d(64),
            nn.LeakyReLU(0.2, inplace=True)  # LeakyReLU prevents dead neurons
        )

        # enc2: 128×128×64 → 64×64×128
        self.enc2 = nn.Sequential(
            nn.Conv2d(64, 128, 4, 2, 1),
            nn.BatchNorm2d(128),
            nn.LeakyReLU(0.2, inplace=True)
        )

        # enc3: 64×64×128 → 32×32×256
        self.enc3 = nn.Sequential(
            nn.Conv2d(128, 256, 4, 2, 1),
            nn.BatchNorm2d(256),
            nn.LeakyReLU(0.2, inplace=True)
        )

        # enc4: 32×32×256 → 16×16×512
        self.enc4 = nn.Sequential(
            nn.Conv2d(256, 512, 4, 2, 1),
            nn.BatchNorm2d(512),
            nn.LeakyReLU(0.2, inplace=True)
        )

        # BOTTLENECK (at 16×16 resolution)
        # 3 residual blocks for deep feature learning without dimensionality change
        self.bottleneck = nn.Sequential(
            ResidualBlock(512),
            ResidualBlock(512),
            ResidualBlock(512)
        )

        # DECODER (Upsampling path with skip connections)
        # ConvTranspose2d: Learned upsampling (stride=2 doubles spatial dimensions)

        # dec4: 16×16×512 → 32×32×256
        self.dec4 = nn.Sequential(
            nn.ConvTranspose2d(512, 256, 4, 2, 1),
            nn.BatchNorm2d(256),
            nn.ReLU(inplace=True)
        )

        # dec3: 32×32×512 → 64×64×128 (input=512 due to concatenation with enc3)
        self.dec3 = nn.Sequential(
            nn.ConvTranspose2d(512, 128, 4, 2, 1),
            nn.BatchNorm2d(128),
            nn.ReLU(inplace=True)
        )

        # dec2: 64×64×256 → 128×128×64 (input=256 due to concatenation with enc2)
        self.dec2 = nn.Sequential(
            nn.ConvTranspose2d(256, 64, 4, 2, 1),
            nn.BatchNorm2d(64),
            nn.ReLU(inplace=True)
        )

        # dec1: 128×128×128 → 256×256×64 (input=128 due to concatenation with enc1)
        self.dec1 = nn.Sequential(
            nn.ConvTranspose2d(128, 64, 4, 2, 1),
            nn.BatchNorm2d(64),
            nn.ReLU(inplace=True)
        )

        # FINAL OUTPUT LAYER
        # Projects features to image space: 256×256×64 → 256×256×CHANNELS
        # Tanh activation: outputs in [-1, 1] range (matches normalized input)
        self.final = nn.Sequential(
            nn.Conv2d(64, CHANNELS, 3, 1, 1),
            nn.Tanh()
        )

    def forward(self, x):
        """
        Forward pass with U-Net architecture.

        Technical flow:
        1. Encoder extracts multi-scale features (e1, e2, e3, e4)
        2. Bottleneck processes deepest features
        3. Decoder upsamples while concatenating encoder features
        4. Skip connections preserve spatial details lost during downsampling

        Tensor shapes (for 256×256 input):
        x: [B, 1, 256, 256]
        e1: [B, 64, 128, 128]
        e2: [B, 128, 64, 64]
        e3: [B, 256, 32, 32]
        e4: [B, 512, 16, 16]
        b: [B, 512, 16, 16]
        d4: [B, 256, 32, 32] → concat → [B, 512, 32, 32]
        d3: [B, 128, 64, 64] → concat → [B, 256, 64, 64]
        d2: [B, 64, 128, 128] → concat → [B, 128, 128, 128]
        d1: [B, 64, 256, 256]
        output: [B, 1, 256, 256]
        """
        # Encoder: progressive downsampling
        e1 = self.enc1(x)
        e2 = self.enc2(e1)
        e3 = self.enc3(e2)
        e4 = self.enc4(e3)

        # Bottleneck: deep feature processing
        b = self.bottleneck(e4)

        # Decoder: progressive upsampling with skip connections
        d4 = self.dec4(b)
        d4 = torch.cat([d4, e3], dim=1)  # Concatenate along channel dimension

        d3 = self.dec3(d4)
        d3 = torch.cat([d3, e2], dim=1)

        d2 = self.dec2(d3)
        d2 = torch.cat([d2, e1], dim=1)

        d1 = self.dec1(d2)

        return self.final(d1)


# ======================================
# PATCHGAN DISCRIMINATOR
# ======================================
class ImprovedDiscriminator(nn.Module):
    """
    PatchGAN discriminator for texture realism assessment.

    Technical design:
    - Operates on patches rather than full images
    - Each output pixel judges a 70×70 receptive field in input
    - Encourages high-frequency detail (sharp edges, textures)
    - Concatenates blur+sharp to judge pair authenticity

    Architecture: 5 convolutional layers with progressive downsampling
    Input: 256×256×2 → Output: 15×15×1 (each value = real/fake probability for patch)
    """

    def __init__(self):
        super().__init__()
        self.model = nn.Sequential(
            # Layer 1: 256×256×2 → 128×128×64 (no BatchNorm in first layer - common practice)
            nn.Conv2d(CHANNELS * 2, 64, 4, 2, 1),
            nn.LeakyReLU(0.2, inplace=True),

            # Layer 2: 128×128×64 → 64×64×128
            nn.Conv2d(64, 128, 4, 2, 1),
            nn.BatchNorm2d(128),
            nn.LeakyReLU(0.2, inplace=True),

            # Layer 3: 64×64×128 → 32×32×256
            nn.Conv2d(128, 256, 4, 2, 1),
            nn.BatchNorm2d(256),
            nn.LeakyReLU(0.2, inplace=True),

            # Layer 4: 32×32×256 → 16×16×512
            nn.Conv2d(256, 512, 4, 2, 1),
            nn.BatchNorm2d(512),
            nn.LeakyReLU(0.2, inplace=True),

            # Layer 5: 16×16×512 → 15×15×1 (final classification layer)
            nn.Conv2d(512, 1, 4, 1, 1),
            nn.Sigmoid()  # Output: probability in [0, 1]
        )

    def forward(self, blur, sharp):
        """
        Judges authenticity of (blur, sharp) image pair.

        Technical details:
        - Concatenates inputs along channel dimension
        - Outputs spatial map of real/fake probabilities
        - Each output pixel judges a local patch in input

        Args:
            blur: Blurred input image [B, C, H, W]
            sharp: Sharp output image [B, C, H, W]

        Returns:
            Probability map [B, 1, 15, 15] where each value ∈ [0, 1]
        """
        x = torch.cat([blur, sharp], dim=1)  # Concatenate: 2C channels
        return self.model(x)


# ======================================
# PERCEPTUAL LOSS (VGG-BASED)
# ======================================
class PerceptualLoss(nn.Module):
    """
    Perceptual loss using pretrained VGG16 features.

    Technical rationale:
    - Pixel-wise MSE/L1 loss can produce blurry results
    - Perceptual loss compares high-level features (textures, edges)
    - Uses VGG16 trained on ImageNet (frozen weights)
    - Extracts features from layer relu3_3 (16th layer)

    Mathematical formulation:
    L_perceptual = MSE(VGG(pred), VGG(target))
    where VGG extracts intermediate feature representations
    """

    def __init__(self):
        super().__init__()
        # Load pretrained VGG16 and extract feature extractor
        vgg = models.vgg16(pretrained=True).features

        # Use first 16 layers (up to relu3_3)
        # This level captures mid-level features (textures, patterns)
        self.feature_extractor = nn.Sequential(*list(vgg.children())[:16]).eval()

        # Freeze VGG parameters (no gradient updates)
        for param in self.feature_extractor.parameters():
            param.requires_grad = False

        # ImageNet normalization (required for pretrained VGG)
        self.normalize = transforms.Normalize(
            mean=[0.485, 0.456, 0.406],
            std=[0.229, 0.224, 0.225]
        )

    def forward(self, pred, target):
        """
        Computes perceptual loss between predicted and target images.

        Technical steps:
        1. Denormalize from [-1, 1] to [0, 1]
        2. Convert grayscale to RGB if needed (VGG requires 3 channels)
        3. Apply ImageNet normalization
        4. Extract VGG features
        5. Compute MSE between feature maps

        Args:
            pred: Generated image [B, C, H, W] in [-1, 1]
            target: Ground truth image [B, C, H, W] in [-1, 1]

        Returns:
            Scalar perceptual loss value
        """
        # Denormalize: [-1, 1] → [0, 1]
        pred = (pred + 1) / 2
        target = (target + 1) / 2

        # VGG requires 3 channels - replicate grayscale if needed
        if pred.shape[1] == 1:
            pred = pred.repeat(1, 3, 1, 1)
            target = target.repeat(1, 3, 1, 1)

        # Apply ImageNet normalization (batch-wise)
        pred = torch.stack([self.normalize(p) for p in pred])
        target = torch.stack([self.normalize(t) for t in target])

        # Extract features and compute loss
        pred_features = self.feature_extractor(pred)
        target_features = self.feature_extractor(target)

        return nn.functional.mse_loss(pred_features, target_features)


# ======================================
# VALIDATION FUNCTION
# ======================================
def full_validation(G, test_loader):
    """
    Comprehensive validation using PSNR and SSIM metrics.

    Technical details:
    - PSNR (Peak Signal-to-Noise Ratio): Measures pixel-level accuracy
      Formula: PSNR = 20 * log10(MAX_I / sqrt(MSE))
      Higher is better (typically 20-40 dB for natural images)

    - SSIM (Structural Similarity Index): Measures perceptual quality
      Considers luminance, contrast, and structure
      Range: [-1, 1], where 1 = identical images

    Args:
        G: Generator network
        test_loader: DataLoader for test set

    Returns:
        mean_psnr: Average PSNR across test set
        mean_ssim: Average SSIM across test set
    """
    G.eval()  # Set to evaluation mode (disables dropout, uses running stats for BatchNorm)
    psnr_vals = []
    ssim_vals = []

    with torch.no_grad():  # Disable gradient computation (saves memory)
        for blur, sharp in test_loader:
            blur = blur.to(DEVICE)
            sharp = sharp.to(DEVICE)

            # Generate deblurred images
            fake = G(blur)

            # Compute metrics for each image in batch
            for i in range(blur.shape[0]):
                # Denormalize: [-1, 1] → [0, 255] uint8
                fake_np = ((fake[i].cpu().numpy().transpose(1, 2, 0) + 1) * 127.5).astype(np.uint8)
                sharp_np = ((sharp[i].cpu().numpy().transpose(1, 2, 0) + 1) * 127.5).astype(np.uint8)

                # Compute PSNR
                p = psnr(sharp_np, fake_np)

                # Compute SSIM with appropriate parameters
                # FIX: win_size=3 for small images (default=7 causes error for <7×7 images)
                # multichannel=True for RGB, False for grayscale
                if CHANNELS == 3:
                    s = ssim(sharp_np, fake_np, data_range=255, channel_axis=2, win_size=3)
                else:
                    s = ssim(sharp_np.squeeze(), fake_np.squeeze(), data_range=255, win_size=3)

                psnr_vals.append(p)
                ssim_vals.append(s)

    return np.mean(psnr_vals), np.mean(ssim_vals)


# ======================================
# MAIN TRAINING PIPELINE
# ======================================
def main():
    """
    Complete training pipeline for image deblurring GAN.

    Pipeline stages:
    1. Dataset loading and validation
    2. Visual inspection of samples
    3. Statistical analysis
    4. Model initialization
    5. Training loop with validation
    6. Metric tracking and visualization
    7. Final evaluation and model saving
    """

    print("Using device:", DEVICE)
    print("Image Mode:", MODE_NAME)

    # ==================== STAGE 1: DATASET LOADING ====================
    # Load all image paths using glob pattern matching
    train_blur = sorted(glob.glob(TRAIN_BLUR_PATH + "/*"))
    train_sharp = sorted(glob.glob(TRAIN_SHARP_PATH + "/*"))
    test_blur = sorted(glob.glob(TEST_BLUR_PATH + "/*"))
    test_sharp = sorted(glob.glob(TEST_SHARP_PATH + "/*"))

    # Sanity check: ensure paired datasets
    assert len(train_blur) == len(train_sharp), "Unequal training pairs!"
    assert len(test_blur) == len(test_sharp), "Unequal testing pairs!"

    print("\n========= DATASET OVERVIEW =========")
    print("Training Blur:", len(train_blur))
    print("Training Sharp:", len(train_sharp))
    print("Testing Blur:", len(test_blur))
    print("Testing Sharp:", len(test_sharp))

    # ==================== STAGE 2: VISUAL INSPECTION ====================
    # Sample 5 random pairs for manual inspection
    idxs = random.sample(range(len(train_blur)), 5)
    blurs = []
    sharps = []

    for idx in idxs:
        blur_img = cv2.imread(train_blur[idx])
        sharp_img = cv2.imread(train_sharp[idx])

        # Convert color space based on mode
        if USE_RGB == 1:
            blur_img = cv2.cvtColor(blur_img, cv2.COLOR_BGR2RGB)
            sharp_img = cv2.cvtColor(sharp_img, cv2.COLOR_BGR2RGB)
        else:
            blur_img = cv2.cvtColor(blur_img, cv2.COLOR_BGR2GRAY)
            sharp_img = cv2.cvtColor(sharp_img, cv2.COLOR_BGR2GRAY)

        blurs.append(blur_img)
        sharps.append(sharp_img)

    # Save visualization
    save_visual_samples(blurs, sharps, f"{OUTPUT_DIR}/inspection.png",
                        mode="gray" if USE_RGB == 0 else None)

    # ==================== STAGE 3: STATISTICAL ANALYSIS ====================
    # Compute dataset statistics (min, max, mean, std) for normalization validation
    pixels = []
    for path in tqdm(train_blur[:100], desc="Collecting Pixel Stats"):
        img = cv2.imread(path)
        if USE_RGB == 0:
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        pixels.append(img.flatten())

    pixels = np.concatenate(pixels)
    stats = {
        "min": float(pixels.min()),
        "max": float(pixels.max()),
        "mean": float(pixels.mean()),
        "std": float(pixels.std())
    }

    # Save statistics to JSON
    with open(f"{OUTPUT_DIR}/pixel_stats.json", "w") as f:
        json.dump(stats, f, indent=4)

    # ==================== STAGE 4: DATA LOADING ====================
    # Create PyTorch datasets and dataloaders
    train_dataset = GoProDataset(train_blur, train_sharp, augment=AUGMENTATION)
    test_dataset = GoProDataset(test_blur, test_sharp, augment=False)

    # DataLoader: handles batching, shuffling, parallel loading
    train_loader = DataLoader(
        train_dataset,
        batch_size=BATCH_SIZE,
        shuffle=True,  # Randomize order each epoch
        num_workers=0,  # Parallel data loading
        pin_memory=True  # Faster GPU transfer
    )
    test_loader = DataLoader(
        test_dataset,
        batch_size=BATCH_SIZE,
        shuffle=False,
        num_workers=0,
        pin_memory=True
    )

    # ==================== STAGE 5: MODEL INITIALIZATION ====================
    # Initialize generator and discriminator
    G = ImprovedUNetGenerator().to(DEVICE)
    D = ImprovedDiscriminator().to(DEVICE)

    # Loss functions
    adversarial_loss = nn.BCELoss()  # Binary cross-entropy for discriminator
    pixel_loss = nn.L1Loss()  # L1 loss for pixel-wise reconstruction
    perceptual_loss = PerceptualLoss().to(DEVICE)

    # Optimizers: Adam with specific hyperparameters for GAN training
    # Generator learning rate: 0.0001 (standard for GANs)
    # Discriminator learning rate: 0.00005 (half of G to prevent discriminator dominance)
    # Beta1=0.5, Beta2=0.999: standard momentum parameters for GAN optimization
    opt_G = optim.Adam(G.parameters(), lr=0.0001, betas=(0.5, 0.999))
    opt_D = optim.Adam(D.parameters(), lr=0.000005, betas=(0.5, 0.999))

    # Learning rate schedulers: reduce LR by 0.5 every 15 epochs
    scheduler_G = optim.lr_scheduler.StepLR(opt_G, step_size=15, gamma=0.5)
    scheduler_D = optim.lr_scheduler.StepLR(opt_D, step_size=15, gamma=0.5)

    # ==================== STAGE 6: TRAINING LOOP ====================
    epoch_metrics = []
    best_psnr = 0

    print("\n========= STARTING TRAINING =========")
    for epoch in range(EPOCHS):
        G.train()  # Enable training mode
        D.train()

        train_loop = tqdm(train_loader, desc=f"Epoch {epoch + 1}/{EPOCHS}")
        epoch_g_loss = 0
        epoch_d_loss = 0

        for blur, sharp in train_loop:
            blur = blur.to(DEVICE)
            sharp = sharp.to(DEVICE)
            batch_size = blur.size(0)

            # ========== TRAIN DISCRIMINATOR ==========
            # Objective: Maximize log(D(blur, sharp)) + log(1 - D(blur, G(blur)))
            opt_D.zero_grad()

            # Real pair prediction (blur, sharp)
            pred_real = D(blur, sharp)
            # Label smoothing: use 0.9 instead of 1.0 to prevent overconfidence
            valid = torch.ones_like(pred_real) * 0.9
            loss_real = adversarial_loss(pred_real, valid)

            # Fake pair prediction (blur, G(blur))
            fake_sharp = G(blur).detach()  # Detach to prevent generator gradient flow
            pred_fake = D(blur, fake_sharp)
            fake = torch.zeros_like(pred_fake)
            loss_fake = adversarial_loss(pred_fake, fake)

            # Total discriminator loss
            loss_D = (loss_real + loss_fake) / 2
            loss_D.backward()
            opt_D.step()

            # ========== TRAIN GENERATOR ==========
            # Objective: Maximize log(D(blur, G(blur))) + L1 loss + perceptual loss
            opt_G.zero_grad()

            # Generate fake sharp image
            fake_sharp = G(blur)

            # Adversarial loss: fool the discriminator
            pred_fake = D(blur, fake_sharp)
            valid = torch.ones_like(pred_fake)
            loss_gan = adversarial_loss(pred_fake, valid)

            # Pixel-wise reconstruction loss (L1)
            loss_l1 = pixel_loss(fake_sharp, sharp)

            # Perceptual loss (VGG features)
            loss_perceptual = perceptual_loss(fake_sharp, sharp)

            # Weighted combination of losses
            loss_G = (GAN_WEIGHT * loss_gan +
                      L1_LOSS_WEIGHT * loss_l1 +
                      PERCEPTUAL_WEIGHT * loss_perceptual)

            loss_G.backward()
            opt_G.step()

            # Track losses
            epoch_g_loss += loss_G.item()
            epoch_d_loss += loss_D.item()

            # Update progress bar
            train_loop.set_postfix(
                G=f"{loss_G.item():.3f}",
                D=f"{loss_D.item():.3f}",
                L1=f"{loss_l1.item():.3f}"
            )

        # Step learning rate schedulers
        scheduler_G.step()
        scheduler_D.step()

        # ========== VALIDATION ==========
        psnr_val, ssim_val = full_validation(G, test_loader)

        # Save best model
        if psnr_val > best_psnr:
            best_psnr = psnr_val
            torch.save(G.state_dict(), f"{OUTPUT_DIR}/best_generator.pth")
            print(f" New best model saved! PSNR: {psnr_val:.3f}")

        # ========== PERIODIC VISUALIZATION ==========
        if (epoch + 1) % 5 == 0:
            G.eval()
            with torch.no_grad():
                sample_blur, sample_sharp = next(iter(test_loader))
                sample_blur = sample_blur.to(DEVICE)
                sample_sharp = sample_sharp.to(DEVICE)
                sample_fake = G(sample_blur)

            # Create comparison grid
            plt.figure(figsize=(12, 8))
            for i in range(min(3, sample_blur.shape[0])):
                # Denormalize images
                blur_img = ((sample_blur[i].cpu().numpy().transpose(1, 2, 0) + 1) * 127.5).astype(np.uint8)
                fake_img = ((sample_fake[i].cpu().numpy().transpose(1, 2, 0) + 1) * 127.5).astype(np.uint8)
                sharp_img = ((sample_sharp[i].cpu().numpy().transpose(1, 2, 0) + 1) * 127.5).astype(np.uint8)

                plt.subplot(3, 3, i * 3 + 1)
                plt.title("BLUR INPUT")
                plt.imshow(blur_img.squeeze(), cmap="gray" if CHANNELS == 1 else None)
                plt.axis("off")

                plt.subplot(3, 3, i * 3 + 2)
                plt.title(f"GAN OUTPUT (PSNR: {psnr_val:.2f})")
                plt.imshow(fake_img.squeeze(), cmap="gray" if CHANNELS == 1 else None)
                plt.axis("off")

                plt.subplot(3, 3, i * 3 + 3)
                plt.title("SHARP GROUND TRUTH")
                plt.imshow(sharp_img.squeeze(), cmap="gray" if CHANNELS == 1 else None)
                plt.axis("off")

            plt.tight_layout()
            plt.savefig(f"{OUTPUT_DIR}/epoch_{epoch + 1}_samples.png")
            plt.close()

        # Track metrics
        epoch_metrics.append({
            "epoch": epoch + 1,
            "G_loss": float(epoch_g_loss / len(train_loader)),
            "D_loss": float(epoch_d_loss / len(train_loader)),
            "PSNR": float(psnr_val),
            "SSIM": float(ssim_val)
        })

        print(f"Epoch {epoch + 1}: PSNR={psnr_val:.3f} | SSIM={ssim_val:.4f} | Best PSNR={best_psnr:.3f}")

    # ==================== STAGE 7: SAVE METRICS ====================
    with open(f"{OUTPUT_DIR}/metrics_per_epoch.json", "w") as f:
        json.dump(epoch_metrics, f, indent=4)

    # Plot training curves
    plt.figure(figsize=(12, 4))
    epochs = [m['epoch'] for m in epoch_metrics]
    psnrs = [m['PSNR'] for m in epoch_metrics]
    ssims = [m['SSIM'] for m in epoch_metrics]

    plt.subplot(1, 2, 1)
    plt.plot(epochs, psnrs, 'b-', linewidth=2)
    plt.title('PSNR over Epochs')
    plt.xlabel('Epoch')
    plt.ylabel('PSNR (dB)')
    plt.grid(True)

    plt.subplot(1, 2, 2)
    plt.plot(epochs, ssims, 'g-', linewidth=2)
    plt.title('SSIM over Epochs')
    plt.xlabel('Epoch')
    plt.ylabel('SSIM')
    plt.grid(True)

    plt.tight_layout()
    plt.savefig(f"{OUTPUT_DIR}/training_curves.png")
    plt.close()

    # ==================== STAGE 8: FINAL EVALUATION ====================
    G.load_state_dict(torch.load(f"{OUTPUT_DIR}/best_generator.pth"))
    G.eval()

    with torch.no_grad():
        blur, sharp = next(iter(test_loader))
        blur = blur.to(DEVICE)
        fake = G(blur)

    # Denormalize for visualization
    blur_img = ((blur[0].cpu().numpy().transpose(1, 2, 0) + 1) * 127.5).astype(np.uint8)
    fake_img = ((fake[0].cpu().numpy().transpose(1, 2, 0) + 1) * 127.5).astype(np.uint8)
    sharp_img = ((sharp[0].cpu().numpy().transpose(1, 2, 0) + 1) * 127.5).astype(np.uint8)

    # Compute final metrics
    if CHANNELS == 3:
        final_psnr = psnr(sharp_img, fake_img)
        final_ssim = ssim(sharp_img, fake_img, data_range=255, channel_axis=2, win_size=3)
    else:
        final_psnr = psnr(sharp_img.squeeze(), fake_img.squeeze())
        final_ssim = ssim(sharp_img.squeeze(), fake_img.squeeze(), data_range=255, win_size=3)

    # Final visualization
    plt.figure(figsize=(15, 5))

    plt.subplot(1, 3, 1)
    plt.title("BLUR INPUT")
    plt.imshow(blur_img.squeeze(), cmap="gray" if CHANNELS == 1 else None)
    plt.axis("off")

    plt.subplot(1, 3, 2)
    plt.title(f"GAN OUTPUT\nPSNR: {final_psnr:.2f} | SSIM: {final_ssim:.4f}")
    plt.imshow(fake_img.squeeze(), cmap="gray" if CHANNELS == 1 else None)
    plt.axis("off")

    plt.subplot(1, 3, 3)
    plt.title("SHARP GROUND TRUTH")
    plt.imshow(sharp_img.squeeze(), cmap="gray" if CHANNELS == 1 else None)
    plt.axis("off")

    plt.tight_layout()
    plt.savefig(f"{OUTPUT_DIR}/final_result_best_model.png")
    plt.close()

    # Save final models
    torch.save(G.state_dict(), f"{OUTPUT_DIR}/generator_final_{MODE_NAME}.pth")
    torch.save(D.state_dict(), f"{OUTPUT_DIR}/discriminator_final_{MODE_NAME}.pth")

    print("\n TRAINING COMPLETE")
    print(f" Best PSNR achieved: {best_psnr:.3f} dB")
    print(f" All outputs saved in: {OUTPUT_DIR}/")


# ================ MAIN ENTRY POINT ================
if __name__ == '__main__':
    main()