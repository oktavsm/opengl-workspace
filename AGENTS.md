# 🤖 AI Agent Workflow & Instructions

This workspace is fully optimized to work alongside AI Agents for the Computer Graphics course. 

## How to Work With Agents in This Workspace

When you spawn an agent to help you with coursework or experiments, direct the agent to read this document or simply follow these guidelines:

### 1. Mathematics & GLM
Computer graphics heavily relies on linear algebra. When you need help with transformations (translation, rotation, scaling) or projection matrices:
- Ask the agent to use the `glm` library standard conventions.
- Provide specific constraints for your task (e.g., "Rotate the object 90 degrees around the Y-axis without gimbal lock").

### 2. Shader Programming (GLSL)
Writing shaders can be tricky. When asking an agent to write or debug a shader:
- Specify the OpenGL version (e.g., `#version 460 core`).
- Put your shader files in `assets/shaders/`.
- The template already provides `utils::createShaderProgram` in `include/utils.hpp`. Instruct the agent to use this helper when loading shaders.

### 3. Debugging
If you get a black screen (the classic OpenGL problem), instruct the agent to:
- Use `utils::checkGLError()` at strategic points in the render loop.
- Verify that `VAO` and `VBO` are bound correctly.
- Check if the camera matrix (View/Projection) is valid and the object is inside the view frustum.

### 4. Branching
If you ask the agent to start a new task, remind them to use the Makefile:
- `make new-task NAME=task-name`
- `make new-exp NAME=exp-name`
