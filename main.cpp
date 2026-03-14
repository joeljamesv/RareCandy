#include "cpu.hpp"
#include <iostream>

int main() {
  CPU object;
  uint8_t program[] = {0x01, 0x12, 0x02, 0x01, 0x10, 0x03, 0x04};

  // An Array when passed the first address is passed.
  object.cpuExecution(program);
}