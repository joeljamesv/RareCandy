#include "cpu.hpp"
#include <iostream>

void CPU::load(uint8_t number) { A = number; }
void CPU::move() { B = A; }
void CPU::add() { A = A + B; }
void CPU::halt() { std::cout << "halting " << A << "\n"; }
