
# Image Deblurring using Generative Adversarial Networks (GANs)

A comprehensive, production-grade image restoration project focused on designing and training a Conditional Generative Adversarial Network (cGAN) to remove complex motion blur from grayscale images[cite: 1, 2]. This framework effectively restores high-frequency visual details and structural integrity often degraded by camera shake, rapid motion, or low-light environments[cite: 1, 2].

This repository provides a complete deep learning pipeline built from scratch using **PyTorch**, alongside structured academic documentation detailing the mathematical foundations and network optimization strategies[cite: 1, 2].

---

## 🏗️ Architectural Topology

The system utilizes a Conditional GAN (cGAN) framework optimized for end-to-end image-to-image translation[cite: 2]:

1. **Generator (Improved U-Net):** Built on a U-Net encoder-decoder blueprint enhanced with intermediate residual blocks at the bottleneck to process deep features without losing structural information[cite: 1, 2]. The integration of **Skip Connections** directly couples early feature maps with upsampling layers, preserving fine-grained spatial details, sharp edges, and architectural outlines[cite: 1, 2].
2. **Discriminator (PatchGAN):** Unlike standard classifiers that evaluate the global image, the PatchGAN architecture classifies localized sub-patches of size $N \times N$[cite: 1, 2]. This enforces strict architectural focus on high-frequency structural elements like local textures and micro-edges[cite: 1, 2].

---

## 🎯 Hybrid Loss Formulation

To mitigate the oversmoothing artifacts common in pure regression models, the generator optimization is governed by a weighted compound loss function[cite: 1, 2]:

* **Adversarial Loss ($\mathcal{L}_{GAN}$):** Drives the generator to synthesise highly realistic textures, keeping outputs indistinguishable from true sharp frames[cite: 1, 2].
* **Pixel-Wise Reconstruction Loss ($\mathcal{L}_{L1}$):** Computes the Mean Absolute Error (MAE) between the generated output and the ground truth to guarantee absolute pixel alignment and prevent structural drift[cite: 1, 2]:
  $$\mathcal{L}_{L1}(G) = \mathbb{E}_{x,y} \left[ \| y - G(x) \|_1 \right]$$
* **Perceptual Feature Loss ($\mathcal{L}_{perc}$):** Leverages feature maps extracted from the intermediate layers of a pre-trained VGG16 network to optimize high-level visual and structural consistency[cite: 1, 2].

$$\mathbf{L}_{\mathbf{G}} = \mathbf{W}_{\text{GAN}} \cdot \mathbf{L}_{\text{GAN}} + \mathbf{W}_{\text{L1}} \cdot \mathbf{L}_{\text{L1}} + \mathbf{W}_{\text{Perceptual}} \cdot \mathbf{L}_{\text{Perceptual}}$$

---

## 📊 Evaluation & Metrics Tracking

Model convergence and structural fidelity are systematically benchmarked against validation sets using two industry-standard verification metrics:
* **PSNR (Peak Signal-to-Noise Ratio):** Quantifies absolute pixel reconstruction accuracy and noise compression.
* **SSIM (Structural Similarity Index):** Tracks structural preservation, luminance consistency, and contrast mapping relative to human visual perception.

### 📝 Empirical Training Logs
To maintain a clean documentation structure, the complete step-by-step execution metrics and performance indicators across all 50 epochs have been extracted into a separate file. 
* **Full Execution Output:** You can review the complete console output and dynamic tracking logs in [training_log.txt](./training_log.txt).

### 🏆 Key Quantitative Milestones
* **Initial Performance (Epoch 1):** PSNR = `23.907 dB` | SSIM = `0.7069`
* **Optimal Convergence (Epoch 48):** PSNR = **`25.495 dB`** | SSIM = **`0.7745`**
* **Final Stability (Epoch 50):** The Discriminator loss ($D$) stabilized around `0.171`, maintaining a healthy adversarial equilibrium with the Generator ($G$) without any mode collapse.

During execution, the training pipeline generates automated 3-column verification visual grids comparing:
1. **Blur Input:** The degraded source frame.
2. **GAN Output:** The restored frame enriched with real-time PSNR and SSIM scores.
3. **Sharp Ground Truth:** The targeted reference standard.

---

## 💻 Environment Setup & Pipeline Execution

### Prerequisites
Install the required machine learning and image processing dependencies:
```bash
pip install torch torchvision opencv-python numpy matplotlib scikit-image tqdm

```

### Dataset Structure

The dataset pipeline expects a paired directory workflow matching the standard **GoPro** format:

```text
DBlur/Gopro/
├── train/
│   ├── blur/
│   └── sharp/
└── test/
    ├── blur/
    └── sharp/

```

### Configuration & Running

* Channel depth can be dynamically switched between Grayscale ($1$ channel) and RGB ($3$ channels) by adjusting the global `USE_RGB` flag inside the script.


* Execute the complete training and validation pipeline:

```bash
python "main.py"

```