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

#### Using Terminal (NVIDIA PRIME Offload)
If you are on a laptop with a dedicated NVIDIA GPU, use the following command to ensure the application runs on the dedicated GPU:

```bash
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia ./build/komgraf
```

#### Using VS Code (Recommended)
Simply open the project in VS Code, press `F5` or go to **Run and Debug** -> **KomGraf - NVIDIA**. The workspace will automatically build the project and launch the debugger with the correct NVIDIA environment variables.

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
