#include "ui/Widget.hpp"

#include <string>

namespace mayak::ui {
    class Label : public Widget {
    public:
        Label(const std::string& text);
    };
}