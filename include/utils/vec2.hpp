#pragma once

#include <cmath>
#include <cassert>
#include "utils/logger.hpp"

namespace mayak {
    struct vec2 {
        float x, y;
        constexpr vec2(float x = 0, float y = 0) : x(x), y(y) {};
    };

    // constexpr abs for float (std::abs не constexpr в C++17)
    constexpr float fabs_constexpr(float v) {
        return v < 0 ? -v : v;
    }

    // Component-wise addition
    constexpr vec2 operator+(const vec2& a, const vec2& b) {
        return vec2(a.x + b.x, a.y + b.y);
    }

    // Component-wise subtraction
    constexpr vec2 operator-(const vec2& a, const vec2& b) {
        return vec2(a.x - b.x, a.y - b.y);
    }

    // Component-wise multiplication
    constexpr vec2 operator*(const vec2& a, const vec2& b) {
        return vec2(a.x * b.x, a.y * b.y);
    }

    // Component-wise division, asserts and logs on zero divisor
    inline vec2 operator/(const vec2& a, const vec2& b) {
        assert(b.x != 0 && b.y != 0 && "Division by zero in vec2");
        if (b.x == 0 || b.y == 0) {
            MAYAK_LOG_ERROR("Division by zero");
            return vec2(0, 0);
        }
        return vec2(a.x / b.x, a.y / b.y);
    }

    // Equality with epsilon tolerance
    constexpr bool operator==(const vec2& a, const vec2& b) {
        constexpr float eps = 1e-6;
        return fabs_constexpr(a.x - b.x) < eps && fabs_constexpr(a.y - b.y) < eps;
    }

    // Inequality (negation of equality)
    constexpr bool operator!=(const vec2& a, const vec2& b) {
        return !(a == b);
    }
}
