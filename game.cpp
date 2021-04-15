#include <iostream>
#include <ctime>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

using namespace std;

void printBoard(char board[3][3])
{
  cout << "-------------" << endl;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      char block = board[i][j];
      cout << "| " << block << " ";
    }

    cout << "|" << endl;
  }

  cout << "-------------" << endl;
}

int main()
{
  char board[3][3] = {' '};

  char direction;
  bool isXTurn = false;
  int currentX = 0, currentY = 0;

  while (1)
  {
    system("cls");
    printBoard(board);
  }
}