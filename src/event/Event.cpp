#include "core/Init.hpp"
#include "utils/Logger.hpp"
#include "event/Event.hpp"
#include <GLFW/glfw3.h>

namespace mayak {
    static EventCallback current_callback = nullptr;

    void set_event_callback(EventCallback callback) {
        current_callback = callback;
    }

    void emit_event(const Event& e) {
        if (current_callback) current_callback(e);
        else logger::warn("No event callback set");
    }
}