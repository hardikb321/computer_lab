# 🖥️ Integrated Computer Lab — OpenGL 3D Visualization

🔗 **Repository:** [computer_lab](https://github.com/hardikb321/computer_lab.git)

A 3D interactive computer lab simulation built with **C++ and OpenGL (GLUT/GLU)**. It renders a fully modeled room containing a 4×4 grid of 16 computer workstations, each with a desk, monitor, keyboard, mouse, office chair, and CPU cabinet — complete with lighting toggle and free-roam camera controls.

---

## 📸 Preview

The scene renders a first-person-perspective view inside a room with:
- Walls, floor, and roof
- 16 computer stations arranged in a 4×4 grid
- Each station includes: table, monitor (with screen UI), keyboard, mouse, office chair, and CPU tower
- Toggleable lighting (day/night mode)

---

## 📁 Project Structure

```
graphic_project/
├── main.cpp          # Entry point — scene setup, camera, keyboard input, render loop
├── chair.h           # Office chair model (base, seat, armrests, backrest, casters)
├── cpu.h             # CPU cabinet/tower model
├── monitor.h         # Monitor model with screen UI rendering
├── keyboard.h        # Keyboard peripheral model
├── mouse.h           # Mouse peripheral model
├── table.h           # Desk/table model
├── wall.h            # Room walls
├── floor.h           # Room floor
├── roof.h            # Room ceiling/roof
├── app               # Compiled binary (Linux)
└── lab               # Alternative compiled binary (Linux)
```

---

## 🛠️ Prerequisites

### Linux (Ubuntu / Debian)

```bash
sudo apt update
sudo apt install -y g++ freeglut3-dev libglu1-mesa-dev libgl1-mesa-dev
```

### Linux (Fedora / RHEL)

```bash
sudo dnf install -y gcc-c++ freeglut-devel mesa-libGLU-devel mesa-libGL-devel
```

### macOS

Install Xcode Command Line Tools (includes OpenGL and GLUT):

```bash
xcode-select --install
```

> ⚠️ On macOS, replace `<GL/glut.h>` with `<GLUT/glut.h>` in all header files if compilation fails.

### Windows

1. Install [MinGW-w64](https://www.mingw-w64.org/) or use [MSYS2](https://www.msys2.org/).
2. Download [freeglut for MinGW](http://www.transmissionzero.co.uk/software/freeglut-devel/).
3. Copy the freeglut headers, libs, and DLL into your MinGW directories.

---

## ⚙️ Installation

### 1. Clone or Extract the Project

**From zip:**
```bash
unzip graphic_project.zip
cd graphic_project
```

**From git:**
```bash
git clone https://github.com/hardikb321/computer_lab.git
cd computer_lab
```

### 2. Verify Dependencies

```bash
# Confirm g++ is available
g++ --version

# Confirm GLUT headers exist
ls /usr/include/GL/glut.h
```

---

## 🔨 Compilation

### Linux / macOS

```bash
g++ main.cpp -o lab -lGL -lGLU -lglut
```

Or with extra optimization and warnings:

```bash
g++ -O2 -Wall main.cpp -o lab -lGL -lGLU -lglut
```

### Windows (MinGW)

```bash
g++ main.cpp -o lab.exe -lfreeglut -lopengl32 -lglu32
```

> 💡 **Tip:** The repo includes pre-compiled binaries (`app`, `lab`) for Linux. You can run them directly if you're on a compatible Linux system (see Running section below).

---

## ▶️ Running

### Linux / macOS

```bash
./lab
```

Or run the pre-compiled binary:

```bash
chmod +x app
./app
```

### Windows

```bash
lab.exe
```

Make sure `freeglut.dll` is in the same directory as the executable.

---

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` | Move camera forward |
| `S` | Move camera backward |
| `A` | Move camera left |
| `D` | Move camera right |
| `Q` | Rotate scene left (Y-axis) |
| `E` | Rotate scene right (Y-axis) |
| `R` | Rotate scene up (X-axis) |
| `F` | Rotate scene down (X-axis) |
| `L` | Toggle lights on/off (day/night mode) |
| `ESC` | Exit the application |

---

## 💡 Features

- **16 Computer Workstations** arranged in a 4×4 grid, each containing:
  - Desk/table
  - Monitor with rendered screen UI
  - Keyboard
  - Mouse
  - Office chair (with swivel detail)
  - CPU tower/cabinet
- **Room Environment**: Walls, floor, and ceiling/roof
- **Lighting System**: A single overhead GL light with toggle (day = bright background, night = dark background)
- **Free Camera**: Move and rotate freely through the 3D scene
- **Perspective Projection**: 45° FOV via `gluPerspective`
- **Depth Buffering & Anti-aliasing**: Uses `GLUT_DEPTH` and `GLUT_MULTISAMPLE`

---

## 🏗️ Architecture Overview

```
main.cpp
  ├── init()              → Enable depth test, lighting, GL_COLOR_MATERIAL
  ├── display()           → Clear buffers, set camera, apply rotation, draw scene
  │     ├── drawRoom()          → Calls drawWalls(), drawRoof(), drawFloor()
  │     └── drawComputerStation(x, z)  → Assembles all 6 peripherals per station
  ├── keyboardInput()     → Handles WASD, Q/E/R/F, L, ESC
  └── reshape()           → Handles window resize, updates projection matrix
```

Each object (chair, monitor, CPU, etc.) is defined as a standalone header file with its own draw function using OpenGL primitives (`glutSolidCube`, `glutSolidSphere`, `gluCylinder`).

---

## 🐛 Troubleshooting

| Problem | Solution |
|---------|----------|
| `GL/glut.h: No such file or directory` | Install `freeglut3-dev` (Linux) or Xcode tools (macOS) |
| Linker error: `undefined reference to glutInit` | Add `-lglut` (Linux) or `-framework GLUT` (macOS) to compile command |
| Black screen on launch | Check that your GPU supports OpenGL 1.x; try running with a software renderer |
| `./app: Permission denied` | Run `chmod +x app` first |
| macOS: deprecated GLUT warnings | Add `-Wno-deprecated` to suppress, or use XQuartz |

---

## 📜 Git History

| Commit | Description |
|--------|-------------|
| `84df5ca` | Add lighting toggle feature |
| `0586dfc` | Refactor monitor drawing code and improve comments |
| `3f0712a` | Change monitor screen color to white and update text |
| `dae17ed` | Refactor monitor drawing and add Google homepage content |
| `cc3236d` | Refactor monitor drawing functions for consistency |
| `37ceb84` | Enhance monitor drawing with bitmap text and UI elements |
| `cf29535` | Initial commit |

---

## 📄 License

This project is academic/educational. No license file is included — please contact the author before redistributing.