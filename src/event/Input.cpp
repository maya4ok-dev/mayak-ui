#include "core/Init.hpp"
#include "event/Input.hpp"

namespace {
    
}

namespace mayak::core::input {
    enum keyboard_key {
        KEY_ESCAPE = GLFW_KEY_ESCAPE,
        KEY_ENTER = GLFW_KEY_ENTER,
        KEY_LEFT = GLFW_KEY_LEFT,
        KEY_RIGHT = GLFW_KEY_RIGHT,
        KEY_UP = GLFW_KEY_UP,
        KEY_DOWN = GLFW_KEY_DOWN,
        KEY_SPACE = GLFW_KEY_SPACE,
        KEY_PAGE_UP = GLFW_KEY_PAGE_UP,
        KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
        KEY_HOME = GLFW_KEY_HOME,
        KEY_END = GLFW_KEY_END,
        KEY_DELETE = GLFW_KEY_DELETE,
        KEY_BACKSPACE = GLFW_KEY_BACKSPACE
    };

    enum mouse_button {
        LEFT = GLFW_MOUSE_BUTTON_LEFT,
        RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
        MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE,
        BUTTON_4 = GLFW_MOUSE_BUTTON_4,
        BUTTON_5 = GLFW_MOUSE_BUTTON_5
    };

    enum controller_button {
        A = GLFW_GAMEPAD_BUTTON_A,
        B = GLFW_GAMEPAD_BUTTON_B,
        X = GLFW_GAMEPAD_BUTTON_X,
        Y = GLFW_GAMEPAD_BUTTON_Y,
        LEFT_BUMPER = GLFW_GAMEPAD_BUTTON_LEFT_BUMPER,
        RIGHT_BUMPER = GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER,
        BACK = GLFW_GAMEPAD_BUTTON_BACK,
        START = GLFW_GAMEPAD_BUTTON_START,
        GUIDE = GLFW_GAMEPAD_BUTTON_GUIDE,
        LEFT_THUMB = GLFW_GAMEPAD_BUTTON_LEFT_THUMB,
        RIGHT_THUMB = GLFW_GAMEPAD_BUTTON_RIGHT_THUMB,
        DPAD_UP = GLFW_GAMEPAD_BUTTON_DPAD_UP,
        DPAD_RIGHT = GLFW_GAMEPAD_BUTTON_DPAD_RIGHT,
        DPAD_DOWN = GLFW_GAMEPAD_BUTTON_DPAD_DOWN,
        DPAD_LEFT = GLFW_GAMEPAD_BUTTON_DPAD_LEFT
    };

    enum controller_axis {
        LEFT_X = GLFW_GAMEPAD_AXIS_LEFT_X,
        LEFT_Y = GLFW_GAMEPAD_AXIS_LEFT_Y,
        RIGHT_X = GLFW_GAMEPAD_AXIS_RIGHT_X,
        RIGHT_Y = GLFW_GAMEPAD_AXIS_RIGHT_Y,
        LEFT_TRIGGER = GLFW_GAMEPAD_AXIS_LEFT_TRIGGER,
        RIGHT_TRIGGER = GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER
    };

//     bool is_key_pressed(Window* window, mayak::core::input::keyboard_key key) {
//         return glfwGetKey(window, key) == GLFW_PRESS;
//     }
}