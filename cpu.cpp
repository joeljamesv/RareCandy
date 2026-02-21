#include "cpu.hpp"
#include <iostream>




          void CPU::load(int number)
          {
               a=number;
          }
          void CPU::move()
          {
               b=a;
          }
          void CPU::add()
          {
               a=a+b;
          }
          void CPU::halt()
          {
               std::cout<<"halting "<<a<<"\n";
          }
