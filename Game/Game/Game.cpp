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
  while (true)
  {
    if (GetAsyncKeyState(VK_DOWN)) return false;
    else if (GetAsyncKeyState(VK_UP)) break;
  }
  while (true)
  {
    view_.clearAll();
    time (&timer_);
    view_.drawInfo(difftime(timer_, startTime_), car_.getSpeed(), car_.getDistance());
    /*std::cout << "Obstacle:" << "x1" << ' ' << obst_.getx1() << ' ' 
      << "x2" << ' ' << obst_.getx2() << ' ' 
      << "y1" << ' ' << obst_.gety1() << ' ' 
      << "y2" << ' ' << obst_.gety2() << '\n';*/
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
 
    if (obst_.checkCrash(car_.getPosition())) return gameOver();

    time_t now;
    time(&now);
    car_.updateDistance(difftime(now, timer_));
    obst_.moveObstacle(car_.getSpeed(), difftime(now, timer_));
    if (obst_.gety1() > Const::roadLength)
    {
      do
      {
        obst_.changePos();
      }
      while (obst_.checkCrash(car_.getPosition()));
    }
    view_.updateObstacle(obst_);
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