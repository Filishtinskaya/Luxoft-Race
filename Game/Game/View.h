#ifndef _VIEW_H_
#define _VIEW_H_

#include <vector>
#include "Const.h"
#include "Car.h"
#include "Obstacle.h"

class View
{
  public:
    View();
    void printView();
    void clearAll();
    void endMessage(int distance);
    void drawInfo(double time, int speed, int distance);
    void startMessage();
    void pauseMessage();
    void updateCar(Car & car);
    void updateObstacle (Obstacle* obst);
  private:
    std::vector <std::vector<char>> picture_; //+2 for borders
    int carX_;
    int ox1_, ox2_, oy1_, oy2_; //obstacle's coordinates
};

#endif
