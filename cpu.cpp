#include "cpu.hpp"
#include <iostream>

void CPU::load() { A = memory[PC]; }
void CPU::move() { B = A; }
void CPU::add() { A = A + B; }

/*The Fetch operation fetches the Instruction stored in that address PC and
places it into IR (Instruction Register) and finally increments the PC to store
the next Instruction*/
void CPU::fetch() {
  IR = memory[PC];
  PC++;
}

/*The decode instruction, reads whatevers in the IR register,
and switches it accordingly
*/
void CPU::decode() {
  switch (IR) {
  case 1:
    load();
    PC++;
    break;
  case 2:
    move();
    break;
  case 3:
    add();
    break;

  default:
    break;
  }
}

void CPU::cpuExecution(uint8_t *program) {
  memory = program;
  PC = 0;
  while (1) {
    fetch();
    decode();
    if (IR == 0x04)
      break;
  }
  std::cout << "CPU Execution done - final value - " << (int)A << std::endl;
}
