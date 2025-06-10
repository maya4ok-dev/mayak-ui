cmake_minimum_required(VERSION 3.10)
project(MayakUI)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include dirs
include_directories(include)
include_directories(extern/glad/include)

# Add tests
add_subdirectory(tests)

# For Catch2 submodule
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.3
)

FetchContent_MakeAvailable(Catch2)

# Grab sources
file (GLOB_RECURSE MAYAKUI_SOURCES
    src/*.cpp
    extern/glad/src/glad.c
)

# Build library
add_library(mayakui STATIC ${MAYAKUI_SOURCES})

# GLFW (submodule)
add_subdirectory(extern/glfw)
target_link_libraries(mayakui PRIVATE glfw)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(mayakui PRIVATE OpenGL::GL)