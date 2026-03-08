#include <cstdint>

class CPU {
private:
  uint8_t A;
  uint8_t B;
  uint16_t PC;
  uint8_t IR;

  int halted = false; // This is again a register - so needs to removed and
                      // another solution to break the loop

  void load(uint8_t NUM);
  void move();
  void add();
  void halt();
  void fetch(uint8_t *program);
  void decode();
  void execute();

public:
  void cpuExecution(uint8_t *program);
};