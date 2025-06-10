#include <catch2/catch_test_macros.hpp>
#include "event/Input.hpp" // твой файл

TEST_CASE("Rect.contains() works", "[math]") {
    mayak::ui::Rect r{100, 100, 200, 150};

    REQUIRE(r.contains(150, 120));      // внутри
    REQUIRE_FALSE(r.contains(50, 50));  // вне
}
