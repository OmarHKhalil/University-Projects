# 3D Football Stadium — OpenGL

A university **Computer Graphics** project that renders an interactive **3D football (soccer) stadium** using **OpenGL** and **GLUT** (FreeGLUT). The scene includes a full pitch with markings, goals, stands, seating, team banners, and simple animations—all built in a single C++ source file.

## Features

- **Football pitch** with grass, boundary lines, center line, and penalty areas
- **Goals** at both ends, including posts, crossbars, and net geometry
- **Stadium environment**: tiered stands, seats, benches, corner flags, and surrounding ground
- **Team patches** (striped banners) on both sides of the field
- **First-person camera** — walk around and look at the scene from inside the stadium
- **Lighting** — toggle OpenGL lighting on or off
- **Animations**
  - Moving objects along the pitch (timer-driven)
  - Optional **roof / surface** open and close effects
- **Display lists** for reusable geometry (e.g. chairs, benches) to improve draw performance
- Custom **`lines`** helper class for drawing 3D box-shaped line segments (field markings, structures)

## Tech Stack

| Component | Library / Tool |
|-----------|----------------|
| Language | C++ |
| Graphics API | OpenGL |
| Window / Input | GLUT (FreeGLUT) |
| Utilities | GLU (quadrics, `gluLookAt`, etc.) |
| IDE / Build | [Code::Blocks](https://www.codeblocks.org/) (`hhh.cbp`) |
| Compiler | MinGW-w64 (GCC) on Windows |

**Linked libraries:** `freeglut`, `opengl32`, `glu32`, `winmm`, `gdi32`

## Requirements

- **Windows** (project is configured for MinGW on Windows)
- **Code::Blocks** with **MinGW-w64** toolchain, **or** equivalent GCC + FreeGLUT setup
- **FreeGLUT** development libraries installed and available to the linker (as in the Code::Blocks project file)

## Getting Started

### Option 1: Code::Blocks (recommended)

1. Clone or download this repository.
2. Open `hhh.cbp` in Code::Blocks.
3. Ensure MinGW and FreeGLUT include/lib paths match your installation (edit project **Build options → Linker/Compiler** if needed).
4. Select **Debug** or **Release** and click **Build**.
5. Run the executable:
   - Debug: `bin/Debug/hhh.exe`
   - Release: `bin/Release/hhh.exe`

### Option 2: Command line (MinGW)

Adjust include and library paths to match your system:

```bash
g++ -Wall -O2 main.cpp -o stadium.exe ^
  -I"C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include" ^
  -L"C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/lib" ^
  -lfreeglut -lopengl32 -lglu32 -lwinmm -lgdi32
```

Then run:

```bash
stadium.exe
```

## Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Turn left |
| `D` | Turn right |
| `↑` / `↓` / `→` | Adjust camera height (`EY`) |
| `O` | Enable lighting |
| `F` | Disable lighting |
| `G` | Toggle surface / roof **open** animation |
| `H` | Toggle surface / roof **close** animation |
| `Esc` | Exit application |

> **Tip:** Use `W`/`S` and `A`/`D` to explore the stadium. Toggle lighting with `O` and `F` to compare shaded and flat rendering.

## Project Structure

```
.
├── main.cpp      # Entire OpenGL application (~11k lines)
├── hhh.cbp       # Code::Blocks project file
├── hhh.depend    # Code::Blocks dependency cache
├── hhh.layout    # Code::Blocks editor layout
└── README.md
```

Build output (after compiling):

```
bin/Debug/     or     bin/Release/
obj/Debug/           obj/Release/
```

## Implementation Notes

- Rendering is centralized in `DrawGLScene()` with setup in `InitGL()`.
- Geometry is built from **GLUT primitives** (`glutSolidCube`, `glutWireCube`), **GLU cylinders**, and custom **`lines`** quads.
- **`gluLookAt`** implements the roaming camera; position and heading are updated from the keyboard.
- **`glNewList` / `glCallList`** cache repeated objects such as seating.
- Two timers drive animation: `timer()` (surface motion) and `Timer3()` (objects moving along the field).