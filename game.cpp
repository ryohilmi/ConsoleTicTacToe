#include "include/tictactoe.hpp"
#include "include/player.hpp"

#include <iostream>
#include <conio.h>

using namespace std;

string inputName(int playerNum)
{
  string name;
  cout << "Enter player " << playerNum << "'s name : ";
  cin >> name;
  system("cls");

  return name;
}

void printScore(Player player1, Player player2)
{
  cout << "Score" << endl;
  cout << "==================" << endl;
  cout << player1.playerName << "\t:\t" << player1.totalWin << endl;
  cout << player2.playerName << "\t:\t" << player2.totalWin << endl;
  cout << "==================\n\n";
}

int main()
{
  char winnerChar;
  TicTacToe game;

  Player player1(inputName(1));
  Player player2(inputName(2));

  while (1)
  {
    if (game.isDone)
    {
      if (game.isDraw)
      {
        cout << "\n!!!!! DRAW !!!!!\n\n";

        printScore(player1, player2);
      }
      else
      {
        Player *winner = winnerChar == 'X' ? &player1 : &player2;
        winner->win();

        cout << "\n!!!!! " << winner->playerName << " WINS !!!!!\n\n";

        printScore(player1, player2);
      }

      bool end = false;
      char again;

      cout << "Play again? (y / n) ";
      cin >> again;
      end = again == 'y' ? false : true;

      if (end)
      {
        system("cls");
        printScore(player1, player2);
        break;
      }
      else
      {
        game.resetGame();
        continue;
      }
    }

    game.blink();
    game.printBoard();

    if (kbhit())
    {
      game.resetBlink();
      char inputChar = getch();

      if (inputChar == 13)
        game.turn(&winnerChar);

      game.changeDirection(inputChar);
      game.moveCursor();
      game.printBoard();
    }
  }

  return 0;
}