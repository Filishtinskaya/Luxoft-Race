#ifndef _CAR_H_
#define _CAR_H_

class Car{

  public: 
    Car();
    /*
    void setSpeed(int speed);
    void setPosition(int position);
    void setDistance(int position);*/
    long long getDistance();
    int getSpeed();
    int getPosition();

    void updateDistance(double timespan);
    bool moveLeft();
    bool moveRight();
    void speedUp();
    void slowDown();

  private:
    int speed_;
    int position_;
    long long distance_;
};

#endif