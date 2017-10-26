#include <iostream>
#include "Game.h"
#include "Const.h"
#include "conio.h"
#include "time.h"
#include "windows.h"
#include "Obstacle.h"

Game::Game()
{
  time (&startTime_);
  time (&timer_);
}

bool Game::run()
{
  view_.startMessage();
  Obstacle* k = new Obstacle;
  while (true)
  {
    if (GetAsyncKeyState(VK_DOWN)) return false;
    else if (GetAsyncKeyState(VK_UP)) break;
  }
  bool needNewObstacle = false;
  while (true)
  {
    
    if (needNewObstacle)
    {
      do
      {
        delete[] k;
        k = new Obstacle;
      }
      while (k->checkCrash(car_.getPosition()));
    }

    view_.clearAll();
    time (&timer_);
    view_.drawInfo(difftime(timer_, startTime_), car_.getSpeed(), car_.getDistance());
    view_.printView();
    
    if (GetAsyncKeyState(VK_DOWN)) car_.slowDown();
    else if (GetAsyncKeyState(VK_UP)) car_.speedUp();
    else if (GetAsyncKeyState(VK_LEFT)) 
    {
      if (!car_.moveLeft())
        return gameOver();
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
      if (!car_.moveRight())
        return gameOver();
    }
    else if (GetAsyncKeyState(VK_RETURN)) pause();
    else if (GetAsyncKeyState(VK_ESCAPE)) return gameOver();
 
    if (k->checkCrash(car_.getPosition())) return gameOver();

    time_t now;
    time(&now);
    car_.updateDistance(difftime(now, timer_));
    needNewObstacle = !(k -> moveObstacle(car_.getSpeed(), difftime(now, timer_)));
    view_.updateObstacle(k);
    view_.updateCar(car_);
  }
  return gameOver();
}

void Game::pause()
{
  time_t pauseStart, pauseEnd;
  time(&pauseStart);
  view_.pauseMessage();
  while (!GetAsyncKeyState(VK_UP));
  time(&pauseEnd);
  double d = difftime(pauseEnd, pauseStart);
  startTime_ += d;
  timer_ += d;
}

bool Game::gameOver()
{
  view_.clearAll();
  view_.endMessage(car_.getDistance());
  return true;
}