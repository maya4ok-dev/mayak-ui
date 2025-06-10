// --------------------------
//  File: Input.hpp -> MayakUI
//  Made with love by Maya4ok
// --------------------------

#pragma once

#include <unordered_set>

namespace mayak::core::input {
    /// @brief Tells if key's pressed
    /// @param key 
    /// @return True / False or Pressed / Not
    bool is_key_down(int key);

    /// @brief Tells if mouse inside object
    /// @param x Object X position in pixels
    /// @param y Object Y position
    /// @param w Object width
    /// @param h Object height
    /// @param mx Mouse X position
    /// @param my Mouse Y position
    /// @return True / False or Pressed / Not
    /// @warning Is an internal method so don't touch it, i think
    bool is_mouse_inside(int x, int y, int w, int h, int mx, int my);

    /// @brief Tells if user pressed any object
    /// @param object Any: button, label, textbox, etc.
    /// @return True / False or Pressed / Not
    bool is_pressed(int object);

    /// @brief Where's the mouse? – tells mouse X position
    int mouse_x();

    /// @brief Where's the mouse? – tells mouse Y position
    int mouse_y();

    //  -------------------------------------
    //  Internal methods (don't touch it pls 🙏)
    //  -------------------------------------

    /// @brief Tells if key pressed
    /// @param key any key
    /// @warning Is an internal method so don't touch it, i think
    void _key_press(int key);

    /// @brief Tells if key.. isn't pressed anymore
    /// @param key 
    /// @warning Is an internal method so don't touch it, i think
    void _key_release(int key);

    /// @brief Tells if object pressed
    /// @param object button, label, textbox, etc.
    /// @warning Is an internal method so don't touch it, i think
    void _object_press(int object);

    /// @brief Tells if object.. isn't pressed anymore
    /// @param object button, label, textbox, etc.
    /// @warning Is an internal method so don't touch it, i think
    void _object_release(int object);

    /// @brief Nah, you're here now (pls don't loop it, you'll regret it)
    /// @param x New mouse X position
    /// @param y  New mouse Y position
    /// @warning Is an internal method so don't touch it, i think
    void _set_mouse_pos(int x, int y);
}