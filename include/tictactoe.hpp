#include <iostream>
#include <ctime>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

class TicTacToe
{
private:
  char board[3][3] = {' '};

  char direction;
  bool isXTurn = false;
  int currentX = 0, currentY = 0;
  int totalTurn = 0;

public:
  bool isDone = false;
  bool isDraw = false;
  bool isBlinking = true;
  time_t prevTime = time(NULL);

  void printBoard()
  {
    system("cls");
    std::cout << "-------------" << std::endl;

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        char block = (i == currentY && j == currentX && isBlinking)
                         ? '_'
                         : board[i][j];

        std::cout << "| " << block << " ";
      }

      std::cout << "|" << std::endl;
    }

    std::cout << "-------------" << std::endl;
  }

  void moveCursor()
  {
    int x = currentX;
    int y = currentY;

    if (direction == 'U')
    {
      currentY = (y - 1 < 0) ? 2 : y - 1;
    }
    else if (direction == 'D')
    {
      currentY = (y + 1 > 2) ? 0 : y + 1;
    }
    else if (direction == 'L')
    {
      currentX = (x - 1 < 0) ? 2 : x - 1;
    }
    else if (direction == 'R')
    {
      currentX = (x + 1 > 2) ? 0 : x + 1;
    }
  }

  void changeDirection(char inputChar)
  {
    if (inputChar == 'w')
    {
      direction = 'U';
    }
    else if (inputChar == 's')
    {
      direction = 'D';
    }
    else if (inputChar == 'a')
    {
      direction = 'L';
    }
    else if (inputChar == 'd')
    {
      direction = 'R';
    }
    else
    {
      direction = ' ';
    }
  }

  void blink()
  {
    if (difftime(time(NULL), prevTime) == 1)
    {
      isBlinking = !isBlinking;
      prevTime = time(NULL);
    }
  }

  void resetBlink()
  {
    isBlinking = true;
    prevTime = time(NULL);
  }

  void turn(char *winner)
  {
    char *currentBlock = &board[currentY][currentX];
    if (*currentBlock != 'X' && *currentBlock != 'O')
    {
      *currentBlock = isXTurn ? 'X' : 'O';
      isXTurn = !isXTurn;
      isBlinking = false;
      totalTurn++;

      if (totalTurn == 9)
      {
        isDone = true;
        isDraw = true;
        isBlinking = false;
        return;
      }

      *winner = calculateWinner();
      if (*winner == 'X' || *winner == 'O')
      {
        isDone = true;
      };
    }
  }

  char calculateWinner()
  {
    int lines[8][3][2] = {
        {{0, 0}, {1, 0}, {2, 0}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 2}, {1, 2}, {2, 2}},
        {{0, 0}, {0, 1}, {0, 2}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{2, 0}, {2, 1}, {2, 2}},
        {{0, 0}, {1, 1}, {2, 2}},
        {{2, 0}, {1, 1}, {0, 2}},
    };

    for (int i = 0; i < 8; i++)
    {
      int *a = lines[i][0];
      int *b = lines[i][1];
      int *c = lines[i][2];

      if (board[*(a + 1)][*a] != 'X' && board[*(a + 1)][*a] != 'O')
        continue;

      if (board[*(a + 1)][*a] == board[*(b + 1)][*b] && board[*(a + 1)][*a] == board[*(c + 1)][*c])
      {
        return board[*(a + 1)][*a];
      }
    }

    return '_';
  }
};