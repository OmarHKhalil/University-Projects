
# Multipurpose Media Processor (MMN Project)

A comprehensive Windows Forms application built in C# that combines advanced **Image Processing** tools with a fully functional **Audio Player**. This project was developed as part of the MMN university course, demonstrating low-level bitmap manipulation, structural UI patterns, and external library integration.

## 🚀 Features

### 1. Advanced Image Processing
* **Fast Pixel Manipulation:** Uses memory pointer locking (`BitmapData`, `LockBits`) for high-performance pixel processing instead of slow `GetPixel`/`SetPixel` methods.
* **Geometric Shapes & Text:** Real-time rendering of lines, rectangles, customized ellipses, full circles, and mathematical triangles (equilateral calculation).
* **Color Filters & Enhancements:** 
    * Optimized Grayscale conversion using human eye luminosity weights.
    * Channel isolation (Red, Green, Blue, and RG Mix).
    * Custom alpha-blending color filters with adjustable opacity overlays.
* **Transformations:** High-quality Bicubic image resizing, custom-angle rotation with boundary recalculation, and axis flipping (Horizontal/Vertical).
* **Image Blending:** Seamlessly merges two separate images with an adjustable transparency matrix (`ColorMatrix`).

### 2. Audio Player (Powered by NAudio)
* **Format Support:** Seamless playback for `.mp3` audio files.
* **Technical Metadata Inspection:** Extracts and displays crucial audio stream technicalities (Sample Rate, Bits Per Sample) for both MP3 and Wave formats inside a dynamic ListView.
* **Playback Controls:** Standard Play, Pause, and Stop functional workflow.
* **Precise Seeking:** Interactive TrackBar seeking synchronized via a background Timer component.

### 3. Robust UX Utilities
* **Undo/Redo System:** Unlimited state-management utilizing double Stack structures (`Undo` and `Redo` stacks) capturing manual canvas changes.
* **Flexible Exporters:** Multi-format image saver matching user-defined extensions (`.png`, `.jpg`, `.bmp`).
* **Dynamic Zooming:** Safe clamp-bounded Zoom In/Out scaling centered directly within the viewport layout.

---

## 🛠️ Built With

* **Language:** C# (.NET Framework / .NET Core Windows Forms)
* **Audio Core:** [NAudio Library](https://github.com/naudio/NAudio) (Audio manipulation & playback output)
* **Graphics Engine:** GDI+ (`System.Drawing`)

---

## 💻 Installation & Setup

1. **Clone the repository:**
```
bash
git clone [https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git]
```
(https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git)

2. **Open the Project:**
Open the `.sln` file using **Visual Studio 2022** or later.
3. **Restore NuGet Packages:**
Ensure the `NAudio` package is correctly restored via the NuGet Package Manager:

```
bash
   Install-Package NAudio

```

4. **Run the Project:**
Press `F5` or click **Start** in Visual Studio.

---

## 🧠 Architecture Highlights

* **Performance:** By using `LockBits` for custom color filters, the application avoids UI freezes during image rendering by directly manipulating byte arrays in system memory.
* **Mathematics in Code:** The rotation and triangle features utilize standard geometric algorithms ($Height = \frac{\sqrt{3}}{2} \times Base$) to maintain crisp aspect ratios.

```

```
