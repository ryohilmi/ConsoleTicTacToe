#include <iostream>
#include <ctime>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

#include "include/tictactoe.hpp"

using namespace std;

int main()
{
  char winner;
  TicTacToe game;

  while (1)
  {
    if (game.isDone)
    {
      if (game.isDraw)
      {
        cout << endl
             << "!!!!! DRAW !!!!!" << endl;
      }
      else
      {
        cout << endl
             << "!!!!! " << winner << " WINS !!!!!" << endl;
      }

      break;
    }

    game.blink();
    game.printBoard();

    if (kbhit())
    {
      game.resetBlink();
      char inputChar = getch();

      if (inputChar == 13)
        game.turn(&winner);

      game.changeDirection(inputChar);
      game.moveCursor();
      game.printBoard();
    }
  }

  return 0;
}