#include <cstdint>

class CPU {
private:
  uint8_t A;
  uint8_t B;
  uint16_t PC;
  uint8_t IR;

  uint8_t *memory;

  void load(uint8_t NUM);
  void move();
  void add();
  void fetch();
  void decode();
  void execute();

public:
  void cpuExecution(uint8_t *program);
};