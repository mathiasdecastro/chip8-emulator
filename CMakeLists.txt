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