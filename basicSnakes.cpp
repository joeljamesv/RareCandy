/*
Basic screen,
[20]*[20]

The free  |    dots(.)
The food  |    astreix(*)
The snake |    head greater than (>)
The snake |    body hypher(-)
*/

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

int screenHeight = 20;
int screenSize = 20;
char screen[20][20];

void printScreen() {
  for (int i = 0; i < screenHeight; i++) {
    for (int j = 0; j < screenSize; j++) {
      std::cout << screen[i][j];
    }
    std::cout << std::endl;
  }
}

int main() {
  // Screen
  for (int i = 0; i < screenHeight; i++) {
    for (int j = 0; j < screenSize; j++) {
      screen[i][j] = '.';
    }
  }
  printScreen();
  // Randomly scatter the Food
  while (1) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int randomX = rand() % 20;
    int randomY = rand() % 20;

    screen[randomX][randomY] = '*';
    printScreen();
  }
}
