#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

class Obstacle
{
  public:
    Obstacle();
    bool checkCrash(int pos);
    bool moveObstacle(int speed, double timespan);
    int getx1();
    int getx2();
    int gety1();
    int gety2();
  private:
    int x1_,y1_,x2_,y2_;
};

#endif
