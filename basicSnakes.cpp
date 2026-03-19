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
#include <cstring>
#include <iostream>
#include <pthread.h>
#include <random>
#include <thread>

int screenHeight;
int screenWidth;
char screen[10][10];

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1, 10);

void printScreen() {
  std::cout << "\033[H";
  for (int i = 0; i < screenHeight; i++) {
    for (int j = 0; j < screenWidth; j++) {
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

void setupScreen() {
  screenHeight = 10;
  screenWidth = 10;
  memset(screen, '.', sizeof(screen));
}

int main() {
  /*
  Setting up a screen
  The screen is setup as 10*10 char spaces in console.

  A array of ' ' is defined for the screen
  The array is declared globally ease of use.
  */
  setupScreen();
  std::cout << "\033[2J\033[H";
  /*
  PrintScreen
  This would print the screen at that instant.
  The screen is cleared at the first use and for every other uses the
  cursor is placed at the top right and screen is overWritten
  */
  printScreen();

  /*
  ScatterFood function - this would randomly take a pixel between screenHeint
  and screenWidth and randomly place a food ('*') on that pixel
  */

  pthread_t foodDistributionUnit;
  pthread_create(&foodDistributionUnit, NULL, scatterFood, NULL);

  std::this_thread::sleep_for(std::chrono::seconds(10));
  pthread_join(foodDistributionUnit, NULL);

  // int randomX = rand() % 20;
  // int randomY = rand() % 20;
  // printScreen();
  // // Randomly scatter the food and snake controls

  // char snakeHeads[4] = {'<', '>', '^', 'V'};
  // int snakeX = rand() % 20;
  // int snakeY = rand() % 20;

  // screen[snakeX][snakeY] = snakeHeads[1];
  // /*
  // Randomly place a snake head at the start
  // listens to 'W' 'A' 'S' 'D'
  // and choose the snake head from there
  // */
  // char userInput;
  // int whichHead;
  // int currentInput;
  // while (1) {
  //   std::cin >> userInput;
  //   if (userInput == 'w') {
  //     whichHead = 2;
  //     currentInput = 2;
  //   } else if (userInput == 'a') {
  //     whichHead = 0;
  //     currentInput = 0;
  //   } else if (userInput == 's') {
  //     whichHead = 3;
  //     currentInput = 3;
  //   } else if (userInput == 'd') {
  //     whichHead = 1;
  //     currentInput = 1;
  //   }
  //   std::cout << "\033[H";
  //   std::this_thread::sleep_for(std::chrono::seconds(1));
  //   screen[randomX][randomY] = '.';
  //   randomX = rand() % 20;
  //   randomY = rand() % 20;
  //   screen[randomX][randomY] = '*';
  //   screen[snakeX][snakeY] = snakeHeads[whichHead];
  //   printScreen();

  //   if (currentInput == 2) {
  //     snakeX++;
  //   } else if (currentInput == 0) {
  //     snakeY--;
  //   } else if (currentInput == 3) {
  //     snakeX--;
  //   } else if (currentInput == 1) {
  //     snakeY++;
  //   }
  // }
}
