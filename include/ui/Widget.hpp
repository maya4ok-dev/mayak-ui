// this header is for the widget class which is the base class for all ui elements
#pragma once

#include "ui/Label.hpp"
#include "ui/Button.hpp"
#include "ui/Layout.hpp"

namespace mayak::ui {
    class Widget {
    public:
        virtual void onMouseEvent(const mayak::event::MouseEvent& event);
        bool contains(const glm::vec2& position) const;
    };
}