cmake_minimum_required(VERSION 3.10)
project(chip8-emulator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/chip8.cpp
    src/main.cpp
)

add_executable(chip8 ${SOURCES})

if(MSVC)
    target_compile_options(chip8 PRIVATE /W4 /permissive-)
else()
    target_compile_options(chip8 PRIVATE -Wall -Wextra -pedantic -Wshadow)
endif()

include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(catch2)

set(TEST_SOURCES
    tests/chip8_test.cpp
    src/chip8.cpp
)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src ${catch2_SOURCE_DIR}/single_include)