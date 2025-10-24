#include "chip8.hpp"
#include <cstring>
#include <fstream>
#include <iostream>

void Chip8::initialize()
{
    pc = 0x200;
    I = 0;
    sp = 0;
    delay_timer = 0;
    sound_timer = 0;
    memset(memory, 0, sizeof(memory));
    memset(V, 0, sizeof(V));
    memset(stack, 0, sizeof(stack));
    memset(gfx, 0, sizeof(gfx));
}

void Chip8::loadProgram(const char* filename)
{
    std::ifstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cerr << "Error: failed to load " << filename << std::endl;
        return;
    }

    file.read(reinterpret_cast<char*>(&memory[0x200]), 4096 - 0x200);
}

void Chip8::emulateCycle()
{
    uint16_t opcode = memory[pc] << 8 | memory[pc + 1];

    switch (opcode & 0xF000)
    {
        case 0x1000:
            pc = opcode & 0x0FFF;
            break;

        case 0x6000:
        {
            int x = (opcode & 0x0F00) >> 8;
            V[x] = opcode & 0x00FF;
            pc += 2;
            break;
        }

        case 0x00E0:
        {
            memset(gfx, 0, sizeof(gfx));
            pc += 2;
            break;
        }

        case 0x2000:
            stack[sp++] = pc + 2;
            pc = opcode & 0x0FFF;
            break;

        case 0x00EE:
            pc = stack[--sp];
            break;

        default:
            pc += 2;
            break;
    }

    if (delay_timer > 0) --delay_timer;
    if (sound_timer > 0) --sound_timer;
}