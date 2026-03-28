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
#include <termios.h>
#include <atomic>
#include <unistd.h>


std::atomic<char> direction('d'); 
std::atomic<bool> running(true);
termios originalTermios;

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &originalTermios);

    termios raw = originalTermios;
    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios);
}

void* inputThread(void* arg) {
    while (running) {
        char ch = getchar();  // non-blocking now

        if (ch == 'w' && direction != 's') direction = 'w';
        else if (ch == 's' && direction != 'w') direction = 's';
        else if (ch == 'a' && direction != 'd') direction = 'a';
        else if (ch == 'd' && direction != 'a') direction = 'd';
        else if (ch == 'q') running = false;

        usleep(1000); 
    }
    return NULL;
}

int screenHeight;
int screenWidth;
char screen[10][10];

int snakeHeadX,snakeHeadY;
std::vector<std::vector<int>>snakeBody;

std::random_device rd;
std::mt19937 gen(rd());

std::uniform_int_distribution<> dist(1, 9);

void printScreen() {
  std::cout << "\033[H";
  for (int i = 0; i < screenHeight; i++) {
    for (int j = 0; j < screenWidth; j++) {
      std::cout << screen[i][j];
    }
    std::cout << std::endl;
  }
}

void scatterFood() {
    int foodSpotX = dist(gen);
    int foodSpotY = dist(gen);
    screen[foodSpotX][foodSpotY] = '*';
}

void setupScreen() {
  screenHeight = 10;
  screenWidth = 10;
  memset(screen, '.', sizeof(screen));
}

void setupSnake()
{
  snakeHeadX=5;
  snakeHeadY=5;

  snakeBody.push_back({4,5});
}

void snakeMovement()
{
	int X,Y;
	screen[snakeHeadX][snakeHeadY]='o';
	
	for(int i=0;i<snakeBody.size();i++)
	{
		X=snakeBody[i][0];
		Y=snakeBody[i][1];
		screen[X][Y] = '#';
	}

	if(direction == 'w')
	{
		snakeHeadX--;
		snakeBody[0][0]--;
	}
	else if(direction == 's')
	{
		snakeHeadX++;
		snakeBody[0][0]++;
	}
	else if(direction == 'd')
	{
		snakeHeadY++;
		snakeBody[0][1]++;
	}
	else if(direction == 'a')
	{
		snakeHeadY--;
		snakeBody[0][1]--;
	}
}

void clearScreen()
{
  memset(screen,'.',sizeof(screen));
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
  setupSnake();
     enableRawMode();

    pthread_t inputThreadId;
    pthread_create(&inputThreadId, NULL, inputThread, NULL);
  int i=10;
  while(i)
  {
	std::cout<<" direction" <<direction<<std::endl;
    scatterFood();
    snakeMovement();
    printScreen();
    clearScreen();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    i--;   
  }
  disableRawMode();

}
