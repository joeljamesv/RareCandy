#include "cpu.hpp"
#include <iostream>

int main() {
  CPU object;
  object.load(5);
  object.move();
  object.load(10);
  object.add();
  object.halt();
}