#pragma once

#include <GLFW/glfw3.h>
#include "utils/Logger.hpp"

namespace mayak::core {
    bool initialized = false;
    bool init();
    void shutdown(int code);
}