# Chip-8-Emulator

This project is a simple emulator for the CHIP-8, a virtual machine developed in the 1970s for playing games on early microcomputers. The emulator interprets and executes CHIP-8 instructions, replicating the behavior of the original system.

I created this project to apply my newly developed skills in systems programming I learnt in a course where I gained experience simulating a machine with opcodes and managing memory

Developing this project consists of:
- **CPU Emulation:** Simulating the CHIP-8's 16-bit CPU by fetching, decoding, and executing opcodes.
- **Memory Management:** Implementing the CHIP-8's 4KB memory space, including loading programs into memory and managing stack operations.
- **Bitwise Operations:** Utilizing bitwise operations to manipulate data at the bit and byte level, essential for interpreting CHIP-8 opcodes.
- **Graphics Rendering:** Implementing a 64x32 monochrome display using a simple framebuffer, and rendering pixels to the screen.
- **Input Handling:** Mapping and processing input from a hexadecimal keypad to simulate the original CHIP-8 controls.
