/**
 * @file Chip8.cpp
 * @author 0YKahil
 * 
 * Implementation of Chip8 class 
 */

#include "../header/Chip8.h"

Chip8::Chip8() {
    // init PC to rom start address to first load the rom before anything
    pc = ROM_START_ADDRESS;


    uint8_t fontset[FONTSET_SIZE] =
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    // load fonts into memory starting at address 0x50
    for (unsigned int i = 0; i < FONTSET_SIZE; ++i) {
        memory[0x50 + i] = fontset[i];
    }
}

void Chip8::loadROM(char const *filename) {
    // open the file in binary and move our pointer to the end
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (file.is_open()) {
        // allocate size of the file to hold its contents
        std::streampos size = file.tellg(); // get size from position
        char* buffer = new char[size]; // allocate

        // read the file into the buffer
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        // load the contents into our memory beginning at 0x200
        for (long i = 0; i < size; ++i) {
            memory[ROM_START_ADDRESS + i] = buffer[i];
        }

        delete[] buffer; // free our buffer
    }
}