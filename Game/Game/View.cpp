#include <iostream>
#include "math.h"
#include "View.h"
#include "Const.h"


View::View()
{
  carX_ = static_cast <int> (ceil(((Const::roadWidth - 1) / 2)));
  picture_.resize(Const::roadLength);
  for (int i = 0; i < Const::roadLength; i++)
    for (int j = 0; j < Const::roadWidth+2; j++)
      if (j == 0 || j == Const::roadWidth+1)
        picture_[i].push_back('|');
      else 
        picture_[i].push_back(' '); 
    picture_[Const::roadLength - 1][carX_] = '[';
    picture_[Const::roadLength - 1][carX_ + 1] = ']';

}

void View::printView()
{
  for (int i = 0; i < Const::roadLength; i++)
    {
     for (int j = 0; j < Const::roadWidth+2; j++)
       putchar(picture_[i][j]);
     putchar('\n');
    }
}
void View::updateCar(Car & car)
{
  picture_[Const::roadLength-1][carX_] = ' ';
  picture_[Const::roadLength-1][carX_ + 1] = ' ';
  carX_ = car.getPosition();
  picture_[Const::roadLength-1][carX_] = '[';
  picture_[Const::roadLength-1][carX_ + 1] = ']';
}

void View::updateObstacle(Obstacle* obst)
{
  for (int i = ox1_; i <= ox2_; i++)
    for (int j = oy1_; j <= oy2_; j++)
      picture_[j][i] = ' ';

  ox1_ = obst -> getx1();
  ox2_ = obst -> getx2();
  oy1_ = obst -> gety1();
  oy2_ = obst -> gety2();

  for (int i = ox1_; i <= ox2_; i++)
    for (int j = oy1_; j <= oy2_; j++)
      picture_[j][i] = '#';
}

void View::startMessage()
{
  std::cout << "Do you want some races? Press up arrow to continue, press down arrow to exit." << '\n';
}

void View::drawInfo (double time, int speed, int distance)
{
  std::cout << "Escape to quit, enter to pause." << '\n';
  std::cout << "Time: " << time << '\n';
  std::cout << "Speed: " << speed << '\n';
  std::cout << "Distance: " << distance << '\n';
}

void View::pauseMessage()
{
  std::cout << "Game paused. If you want to return, press up arrow.";
}

void View::endMessage (int distance)
{
  std::cout << "GAME OVER with distance: " << distance << '\n';
}

void View::clearAll()
{
  system("cls");
}