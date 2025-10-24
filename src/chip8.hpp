#pragma once
#include <cstdint>
#include <string>

class Chip8
{
    private:
        uint8_t memory[4096];
        uint8_t V[16];
        uint16_t I;
        uint16_t pc;
        uint16_t stack[16];
        uint8_t sp;
        uint8_t delay_timer;
        uint8_t sound_timer;
        uint8_t gfx[64 * 32];

    public:
        void initialize();
        void loadProgram(const char* filename);
        void emulateCycle();

        uint8_t getV(int index) const { return V[index]; }
        uint8_t getPixel(int x, int y) const { return gfx[y * 64 + x]; }
        uint16_t getPC() const { return pc; }
        uint8_t getDelayTimer() const { return delay_timer; }
        uint8_t getSoundTimer() const { return sound_timer; }
};