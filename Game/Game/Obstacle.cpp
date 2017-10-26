#include "time.h"
#include "stdlib.h"
#include "Obstacle.h"
#include "Const.h"
#include "math.h"

Obstacle::Obstacle()
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

bool Obstacle::moveObstacle(int speed, double timespan)
{
  y2_+=speed*timespan;
  y1_+=speed*timespan;
  if (y1_ >= Const::roadLength)
    y1_ = Const::roadLength - 1;
  if (y2_ >= Const::roadLength)
  {
    y2_ = Const::roadLength - 1;
  }
    return false;
  return true;

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