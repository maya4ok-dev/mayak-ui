#include "core/Init.hpp"
#include "utils/Logger.hpp"
#include <cstdlib>
#include <string>

namespace mayak::core {
    bool initialized = false;

    bool init(){
        if (initialized) {
            MAYAK_LOG_DEBUG("Already initialized GLFW");
            return true;
        } else {
            initialized = glfwInit();
            if (!initialized) {
                MAYAK_LOG_ERROR("Failed to initialize GLFW");
                return false;
            }
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            MAYAK_LOG_DEBUG("Initialized GLFW");
            return true;
        }
    }

    void shutdown(int code) {
        MAYAK_LOG_TRACE("Exiting with code " + std::to_string(code));
        if (initialized) glfwTerminate();
        std::exit(code);
    }
}