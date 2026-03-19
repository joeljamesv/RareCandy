/*
Basic screen,
[20]*[20]

The free  |    dots(.)
The food  |    astreix(*)
The snake |    head greater,less, V and PowerOf (>,<,^,V)
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
  std::cout << "\033[2J\033[H";

  int randomX = rand() % 20;
  int randomY = rand() % 20;
  printScreen();
  // Randomly scatter the food and snake controls

  char snakeHeads[4] = {'<', '>', '^', 'V'};
  int snakeX = rand() % 20;
  int snakeY = rand() % 20;

  screen[snakeX][snakeY] = snakeHeads[1];
  /*
  Randomly place a snake head at the start
  listens to 'W' 'A' 'S' 'D'
  and choose the snake head from there
  */
  char userInput;
  int whichHead;
  int currentInput;
  while (1) {
    std::cin >> userInput;
    if (userInput == 'w') {
      whichHead = 2;
      currentInput = 2;
    } else if (userInput == 'a') {
      whichHead = 0;
      currentInput = 0;
    } else if (userInput == 's') {
      whichHead = 3;
      currentInput = 3;
    } else if (userInput == 'd') {
      whichHead = 1;
      currentInput = 1;
    }
    std::cout << "\033[H";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    screen[randomX][randomY] = '.';
    randomX = rand() % 20;
    randomY = rand() % 20;
    screen[randomX][randomY] = '*';
    screen[snakeX][snakeY] = snakeHeads[whichHead];
    printScreen();

    if (currentInput == 2) {
      snakeX++;
    } else if (currentInput == 0) {
      snakeY--;
    } else if (currentInput == 3) {
      snakeX--;
    } else if (currentInput == 1) {
      snakeY++;
    }
  }
}
