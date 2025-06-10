#include "core/Window.hpp"
#include "core/Init.hpp"

namespace mayak::core::window{
    class Window {
    private:
        GLFWwindow* window;
        int width, height;
    public:
        Window(int w, int h, const std::string& title) : width(w), height(h) {
            if (!mayak::core::initialized) {
                MAYAK_LOG_WARN("First initialize GLFW!");
                return;
            }
            window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
            if (!window) {
                MAYAK_LOG_ERROR("Failed to create GLFW window.");
                return;
            }

            glfwMakeContextCurrent(window);

            MAYAK_LOG_DEBUG("Window created successfully!");
        }

        ~Window(){
            if(window) {
                glfwDestroyWindow(window);
            }
        }
    };
};