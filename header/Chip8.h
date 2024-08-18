/**
 * @file Chip8.h
 * @author 0YKahil
 * 
 * Declaration of Chip8 class used to represent the machine
 */

#include <iostream>
#include <stdint.h>
#include <fstream>

/**
 * Chip 8 Emulator with all its components.
 * 
 * More details about them can be found in all_planning_docs/MachineRequirements.txt
 * 
 * Component List:
 * (16) 8-bit registers, (1) 16-bit index register, (1) 16-bit PC register, 
 * 4KB memory, 16 level stack, 8-bit stack pointer, 8-bit delay timer, 8-bit sound timer,
 * 16 key keypad, 64x32 monochrome display memory.
 * 
 * EVERYTHING WILL BE INIT TO 0 IN MEMORY (using {})
 */
class Chip8 {

public:
    uint8_t registers[16]{};    // 16 register array
    uint8_t memory[4096]{};     // memory array of 8 bit items (index is memory address)

    uint16_t index{};           // index register
    uint16_t pc{};              // program counter

    uint16_t stack[16]{};       // 16 level stack to store return addresses
    uint8_t sp{};               // stack pointer

    uint8_t delayTimer{};     
    uint8_t soundTimer{};       // plays sound when not 0

    uint32_t video[64*32]{};    // 64x32 display memory 
    uint16_t opcode;

};
