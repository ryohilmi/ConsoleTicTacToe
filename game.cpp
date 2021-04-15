#include <iostream>
#include <ctime>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

using namespace std;

void printBoard(char board[3][3], int x, int y, bool isBlinking)
{
  cout << "-------------" << endl;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      char block = (i == y && j == x && isBlinking)
                       ? '_'
                       : board[i][j];

      cout << "| " << block << " ";
    }

    cout << "|" << endl;
  }

  cout << "-------------" << endl;
}

void moveCursor(int *x, int *y, char dir)
{
  if (dir == 'U')
  {
    *y = (*y - 1 < 0) ? 2 : *y - 1;
  }
  else if (dir == 'D')
  {
    *y = (*y + 1 > 2) ? 0 : *y + 1;
  }
  else if (dir == 'L')
  {
    *x = (*x - 1 < 0) ? 2 : *x - 1;
  }
  else if (dir == 'R')
  {
    *x = (*x + 1 > 2) ? 0 : *x + 1;
  }
}

char changeDirection(char inputChar)
{
  if (inputChar == 'w')
  {
    return 'U';
  }
  else if (inputChar == 's')
  {
    return 'D';
  }
  else if (inputChar == 'a')
  {
    return 'L';
  }
  else if (inputChar == 'd')
  {
    return 'R';
  }
  else
  {
    return ' ';
  }
}

int main()
{
  char board[3][3] = {' '};

  char direction;
  bool isXTurn = false;
  int currentX = 0, currentY = 0;

  bool isBlinking = true;
  time_t prevTime = time(NULL);

  while (1)
  {
    if (difftime(time(NULL), prevTime) == 1)
    {
      isBlinking = !isBlinking;
      prevTime = time(NULL);
    }

    system("cls");
    printBoard(board, currentX, currentY, isBlinking);

    if (kbhit())
    {
      system("cls");

      isBlinking = true;
      prevTime = time(NULL);

      char inputChar = getch();

      char *currentBlock = &board[currentY][currentX];
      if (inputChar == 13 && *currentBlock != 'X' && *currentBlock != 'O')
      {
        *currentBlock = isXTurn ? 'X' : 'O';
        isXTurn = !isXTurn;
        isBlinking = false;
      }

      direction = changeDirection(inputChar);

      moveCursor(&currentX, &currentY, direction);

      printBoard(board, currentX, currentY, isBlinking);
    }
  }
}