#include "cpu.hpp"
#include <iostream>

void CPU::load(uint8_t number) { A = number; }
void CPU::move() { B = A; }
void CPU::add() { A = A + B; }
void CPU::halt() { halted = true; }
void CPU::cpuExecution(uint8_t *program) {
  while (1) {
    while (*program != 0x04) {
      std::cout << (int)*program << " ";
      program++;
    }
    halted = true;
    if (halted)
      break;
  }
  std::cout << "CPU Execution done\n";
}
