// Renderer.hpp

// I really like this library because it's really simple
// (definitely not just Maya4ok talking to himself)

#pragma once
#include <glad/glad.h>

namespace mayak::gfx {

    struct RendererContext {
        GLuint shaderProgram = 0;
        // someday I'll add VAO, VBO, textures, etc.
    };

    bool LoadShaders(RendererContext& ctx);
    void Use(const RendererContext& ctx);
    void Destroy(RendererContext& ctx);
}