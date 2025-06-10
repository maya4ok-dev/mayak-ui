file(GLOB_RECURSE SOURCES *.cpp)

add_executable(MayakUI_Tests
    main.cpp
    ${SOURCES}
)