#include "time.h"
#include "stdlib.h"
#include "Obstacle.h"
#include "Const.h"
#include "math.h"

Obstacle::Obstacle()
{
  changePos();
}

void Obstacle::changePos()
{
  do
  {
    srand (time(0));
    x2_ = abs (rand() % Const::roadWidth);
    if (x2_ != 0)
      x1_ = abs (rand() % x2_);
    y1_ = 0;
    y2_ = abs (rand() % Const::roadLength);
  }
  while (x2_ - x1_ >= (Const::roadWidth / 3) || x1_ == 0);
}

bool Obstacle::checkCrash(int pos)
{
  if (y1_ <= Const::roadLength-2 && y2_ >= Const::roadLength-1  && x2_ >= pos && x1_ <= pos+1)
    return true;
  return false;
}

void Obstacle::moveObstacle(int speed, double timespan)
{
  y1_ += static_cast <int> (speed*timespan);
  y2_ += static_cast <int> (speed*timespan);
  if (y2_ >= Const::roadLength)
    y2_ = y1_;
}

int Obstacle::getx1()
{
  return x1_;
}

int Obstacle::getx2()
{
  return x2_;
}

int Obstacle::gety1()
{
  return y1_;
}

int Obstacle::gety2()
{
  return y2_;
}