#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
  bool f = 1;
  while (f)
  {
    Game game;
    f = game.run();
  }
  return 0;
}