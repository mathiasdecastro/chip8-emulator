#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "chip8.hpp"

TEST_CASE("CLS clears the screen")
{
    Chip8 chip;
    chip.initialize();
    chip.emulateCycle();

    chip.loadProgram(nullptr);
    chip.emulateCycle();

    uint16_t clsOpcode = 0x00E0;
    chip.emulateCycle();

    for (int i = 0; i < 64*32; ++i)
    {
        REQUIRE(chip.getPixel(i % 64, i / 64) == 0);
    }
}

TEST_CASE("JP jumps to correct address")
{
    Chip8 chip;
    chip.initialize();

    chip.loadProgram(nullptr);
    chip.emulateCycle();

    REQUIRE(chip.getPC() == 0x300);
}