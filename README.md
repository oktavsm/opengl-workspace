# 🎨 Computer Graphics Workspace

A complete, reusable, and modern C++/OpenGL workspace designed for the Computer Graphics course. 

This repository serves as a starting point and template for various OpenGL projects throughout the semester, featuring a clean structure and automated build tasks using CMake and VS Code.

## ✨ Features

- **Modern C++17 Setup:** Configured to use the modern standards of C++.
- **CMake Build System:** Easy to configure and cross-platform build system.
- **VS Code Integration:** Pre-configured `launch.json` and `tasks.json` for seamless debugging (F5 to run).
- **NVIDIA Optimus Ready:** Built-in environment variables for NVIDIA PRIME Render Offload to ensure the dedicated GPU is utilized.
- **Scalable Architecture:** Organized directory structure separating assets, headers, and source code.

## 🛠️ Environment & Dependencies

Make sure you have the following installed before running the project:

- **OS:** Ubuntu 24.04 LTS (or compatible Linux distribution)
- **Compiler:** GCC 13.3 (C++17)
- **Build Tool:** CMake 3.16+
- **Graphics API:** OpenGL 4.6
- **Libraries:**
  - `FreeGLUT`
  - `GLEW`
  - `GLM` (Header-only math library)
- **Hardware:** NVIDIA GeForce GTX 1050 (or any dedicated GPU)

### Installing Dependencies (Ubuntu)

```bash
sudo apt update
sudo apt install build-essential cmake gdb
sudo apt install freeglut3-dev libglew-dev libglm-dev
```

## 🚀 Getting Started

### 1. Build the Project

You can build the project manually via terminal using CMake:

```bash
# Configure the build directory
cmake -S . -B build

# Build the executable
cmake --build build
```

### 2. Run the Project

#### Execution Modes & Shortcuts

| Action | Shortcut / Method | Target File | GPU Engine | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Main Project** | Press **`F5`** | `src/main.cpp` (via CMake) | **NVIDIA GTX 1050** | Built for semester project template (`GLUT_DOUBLE` + `glutSwapBuffers`). |
| **Active / Experiment File** | Press **`Ctrl + Shift + F5`** | Current active `.cpp` in editor | **Default GPU (AMD Mesa)** | Best for textbook examples (`docs/ExperimenterSource`), fast test files, single-buffered legacy code (`GLUT_SINGLE`). |
| **Active File on NVIDIA** | `Terminal` ➔ `Run Task...` ➔ `Run Active OpenGL File (NVIDIA)` | Current active `.cpp` in editor | **NVIDIA GTX 1050** | For standalone files requiring NVIDIA dGPU (must use `GLUT_DOUBLE`). |

#### Using Terminal

- **Run Main Project on NVIDIA (PRIME Offload):**
  ```bash
  __NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia ./build/komgraf
  ```
- **Run Main Project on Default / Integrated GPU:**
  ```bash
  ./build/komgraf
  ```

#### Working with Course Resources (`docs/ExperimenterSource`)

The folder `docs/ExperimenterSource` contains textbook sample code (from *Computer Graphics Through OpenGL: From Theory to Experiments* by Sumanta Guha).

1. **Direct Run**: Open any `.cpp` file directly inside `docs/ExperimenterSource/...` and press **`Ctrl + Shift + F5`**. It compiles into `build/` and runs immediately.
2. **Copying to `src/`**: You can copy any `.cpp` file into `src/`. If the program depends on local headers (like `getBMP.h` or `loadOBJ.h`), copy those `.h` files into `src/` or `include/` as well, open the `.cpp` file, and press **`Ctrl + Shift + F5`**.
3. **Understanding the Black Screen Issue on Wayland**:
   The textbook codes use legacy `GLUT_SINGLE` + `glFlush()`. Under Linux Wayland, single-buffered windows do not present frames through NVIDIA PRIME GLX offload (resulting in a blank black screen). Running via **`Ctrl + Shift + F5`** runs on the primary display GPU where `GLUT_SINGLE` renders properly. To run such code on NVIDIA, change `GLUT_SINGLE` to `GLUT_DOUBLE` in `glutInitDisplayMode()` and replace `glFlush()` with `glutSwapBuffers()`.

#### Running an Experiment File in VS Code
`F5` always builds and debugs `src/main.cpp` through CMake. To run another standalone OpenGL file such as `src/circle.cpp`, open the file and press `Ctrl+Shift+F5`. This builds and runs the active `.cpp` file with the project OpenGL libraries.

The active file must provide its own `int main()`. On a new VS Code installation, run **Tasks: Run Task** -> **Run Active OpenGL File** or bind that task to your preferred shortcut.

## 🧩 Template Functions Explained (`src/main.cpp`)

The base template comes with a few essential functions to get you started:

- **`init()`**: Called once at the start. Used to set up initial OpenGL states, like the background clear color (`glClearColor`) and enabling depth testing (`GL_DEPTH_TEST`).
- **`display()`**: The main rendering loop. This is where you draw your objects. It is called automatically by GLUT whenever the window needs to be redrawn. Always starts with `glClear()` and ends with `glutSwapBuffers()`.
- **`reshape(int width, int height)`**: Called whenever the window is resized. Used to adjust the `glViewport` and update the `GL_PROJECTION` matrix (e.g., `glOrtho` or `gluPerspective`) so your drawing scales correctly.
- **`main()`**: The entry point of the program. It initializes FreeGLUT, creates the window, initializes GLEW to load OpenGL functions, and starts the infinite `glutMainLoop()`.

## 📂 Project Structure

```text
.
├── assets/                 # 3D Models, Textures, and Shaders
│   ├── models/
│   ├── shaders/
│   └── textures/
├── include/                # Header files (.h, .hpp)
├── src/                    # Source files (.cpp)
│   └── main.cpp            # Application entry point
├── build/                  # CMake build output directory (Ignored in Git)
├── .vscode/                # VS Code workspace settings and configurations
├── CMakeLists.txt          # CMake configuration file
└── README.md               # Project documentation
```

## 📚 Course Information

- **Course:** Computer Graphics
- **Major:** Informatics Engineering / Computer Science
