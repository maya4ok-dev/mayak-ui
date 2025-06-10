#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

#include "utils/Logger.hpp"
#include "gfx/Renderer.hpp"

namespace {
    const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(0.7f, 0.2f, 0.3f, 1.0f);
        }
    )";

    bool CheckCompileErrors(GLuint shader, const std::string& type) {
        GLint success;
        GLchar infoLog[1024];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            MAYAK_LOG_ERROR("Error while compiling " + type + " shader: " + infoLog);
            return false;
        }
        return true;
    }
    bool CheckLinkErrors(GLuint program) {
        GLint success;
        GLchar infoLog[1024];
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(program, 1024, NULL, infoLog);
            MAYAK_LOG_ERROR(std::string("Error while linking shader program: ") + infoLog);
            return false;
        }
        return true;
    }

}

/// @brief Compiles and links shaders, stores shaderProgram in given ctx.
///
/// Compiles and links vertex and fragment shaders.
/// Stores the resulting shader program in the given renderer context.
/// This is a barebones setup w/o VAO/VBO, but they're planned.
///
/// @param ctx Renderer context, saves shaderProgram (someday VAO, VBO, etc.)
/// @return True if shaders compiled and linked successfully, false otherwise.
/// @see mayak::gfx::RendererContext
bool mayak::gfx::LoadShaders(RendererContext& ctx) {
    // Compile vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    
    // Check for compile errors
    if (!CheckCompileErrors(vertexShader, "vertex shader")) {
        glDeleteShader(vertexShader);
        return false;
    }

    // Compile fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Check for compile errors
    if (!CheckCompileErrors(fragmentShader, "fragment shader")) {
        glDeleteShader(fragmentShader);
        return false;
    }

    // Link shaders
    ctx.shaderProgram = glCreateProgram();
    glAttachShader(ctx.shaderProgram, vertexShader);
    glAttachShader(ctx.shaderProgram, fragmentShader);
    glLinkProgram(ctx.shaderProgram);

    if (!CheckLinkErrors(ctx.shaderProgram)) {
        glDeleteProgram(ctx.shaderProgram);
        return false;
    }

    // Delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return true;
}

void mayak::gfx::Use(const RendererContext& ctx) {
    glUseProgram(ctx.shaderProgram);
}

void mayak::gfx::Destroy(RendererContext& ctx) {
    if (ctx.shaderProgram) {
        glDeleteProgram(ctx.shaderProgram);
        ctx.shaderProgram = 0;
    }
}