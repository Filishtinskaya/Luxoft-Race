#include "Car.h"
#include "Const.h"
#include <cmath>

Car::Car()
{
  speed_ = 0;
  position_ = static_cast <int> (ceil(((Const::roadWidth - 1) / 2)));
  distance_ = 0;
}

int Car::getSpeed()
{
  return speed_;
}

long long Car::getDistance()
{
  return distance_;
}

/*void Car::setSpeed(int speed)
{
  speed_ = speed;
}

void Car::setPosition(int position)
{
  position_ = position;
}*/


int Car::getPosition()
{
  return position_;
}


bool Car::moveLeft()
{
  if (position_ > 1)
  {
    position_--;
    return true;
  }
  return false;
}



bool Car::moveRight()
{
  if (position_ < Const::roadWidth - 1)
  {
    position_++;
    return true;
  }
  return false;
}



void Car::speedUp()
{
  if (speed_ < Const::maxSpeed)
    speed_++;
}



void Car::slowDown()
{
  if (speed_ > 0)
    speed_--;
}



void Car::updateDistance(double timespan)
{
  distance_+=static_cast <int> (speed_*timespan);
}