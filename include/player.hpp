#include <iostream>

class Player
{
public:
  std::string playerName;
  int totalWin;

  Player(std::string name)
  {
    playerName = name;
    totalWin = 0;
  }

  void win()
  {
    totalWin++;
  }
};