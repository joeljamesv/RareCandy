#include <cstdint>

class CPU {
private:
  uint8_t A;
  uint8_t B;
  uint16_t PC;

  void load(uint8_t NUM);
  void move();
  void add();
  void halt();
  uint8_t fetch();
  void decode();
  void execute();

public:
};