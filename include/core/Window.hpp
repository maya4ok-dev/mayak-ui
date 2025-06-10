#include "utils/Logger.hpp"
#include <GLFW/glfw3.h>
#include <string>
#include <map>

class Window;

namespace mayak::core{
    std::map<int, Window*> windows;
    class Window {
    private:
        GLFWwindow* window;
        int width, height;
    public:
        Window(int w, int h, const std::string& title);
        ~Window();

        int GetWidth() const { return width; }
        int GetHeight() const { return height; }

        // add setters later
    };
};