cmake_minimum_required(VERSION 3.16)

project(komputer_grafis
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# OpenGL
find_package(OpenGL REQUIRED)

# FreeGLUT
find_package(GLUT REQUIRED)

# GLEW
find_package(GLEW REQUIRED)

# Main executable
add_executable(komgraf
    src/main.cpp
)

# Header directories
target_include_directories(komgraf PRIVATE
    ${OPENGL_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Libraries
target_link_libraries(komgraf PRIVATE
    OpenGL::GL
    GLUT::GLUT
    GLEW::GLEW
    GLU
)