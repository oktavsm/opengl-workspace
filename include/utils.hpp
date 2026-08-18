#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

namespace utils {

    // Read a file into a string
    inline std::string readFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filePath << std::endl;
            return "";
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    // Compile a shader and check for errors
    inline GLuint compileShader(GLenum type, const std::string& source) {
        GLuint shader = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(shader, 1, &src, nullptr);
        glCompileShader(shader);

        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cerr << "Shader Compilation Error:\n" << infoLog << std::endl;
        }
        return shader;
    }

    // Create a shader program from vertex and fragment shader files
    inline GLuint createShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) {
        std::string vertexCode = readFile(vertexPath);
        std::string fragmentCode = readFile(fragmentPath);

        GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexCode);
        GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentCode);

        GLuint program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        int success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(program, 512, nullptr, infoLog);
            std::cerr << "Program Linking Error:\n" << infoLog << std::endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return program;
    }

    // Utility to check OpenGL errors
    inline void checkGLError(const char* location = "") {
        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR) {
            std::cerr << "OpenGL Error at " << location << ": " << err << std::endl;
        }
    }
}
