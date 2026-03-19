#include "cpu.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

int main() {
  CPU object;

  std::ifstream romfile("../ROM/rom.bin",std::ios::binary);

  if(!romfile.is_open())
  {
    perror("ERROR");
    exit;
  }

  /*File.read(buffer, size) - reads size byte and places it into buffer array - here it would be program and the size 1 byte*/

  uint8_t byte;
  std::vector<uint8_t> program;
  while(romfile.read(reinterpret_cast<char*>(&byte),1))
  {
    program.push_back(byte);
  }
  object.cpuExecution(program.data());
}