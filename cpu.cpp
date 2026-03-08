#include "cpu.hpp"
#include <iostream>

void CPU::load(uint8_t number) { A = number; }
void CPU::move() { B = A; }
void CPU::add() { A = A + B; }
void CPU::halt() { halted = true; }

/*The Fetch operation fetches the Instruction stored in that address PC and
places it into IR (Instruction Register) and finally increments the PC to store
the next Instruction*/
void CPU::fetch(uint8_t *program) {
  IR = program[PC];
  std::cout << "PC: " << PC << " OPCODE: " << (int)IR << std::endl;
  PC++;
}

void CPU::cpuExecution(uint8_t *program) {
  while (1) {
    fetch(program);
    if (IR == 0x04)
      break;
  }
  std::cout << "CPU Execution done\n";
}
