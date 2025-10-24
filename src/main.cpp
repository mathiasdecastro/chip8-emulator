#include "chip8.hpp"
#include <iostream>

int main()
{
    Chip8 chip;
    chip.initialize();

    chip.emulateCycle();

    std::cout << "Chip8 initialized and cycle emulated!" << std::endl;
    return 0;
}