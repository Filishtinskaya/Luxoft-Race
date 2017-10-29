#ifndef _GAME_H_
#define _GAME_H_

#include <time.h>
#include "Car.h"
#include "View.h"

class Game
{
  public: 
    Game();
    bool run();
    bool gameOver();
    void pause();
  private:
    Car car_;
    View view_;
    Obstacle obst_;
    time_t startTime_;
    time_t timer_;
};

#endif