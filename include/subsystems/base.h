#ifndef _SUBSYSTEMS_BASE_H_
#define _SUBSYSTEMS_BASE_H_

#include "main.h"

class Base {
  private:
    static Base* instance;
    Gyro gyro;
    Base();

    const float leftKp = 0.4;
    const float rightKp = 0.4;
  public:
    void moveBase(int leftSpeed, int  rightSpeed);

    int getLeftIME();
    int getRightIME();

    void moveTo(int distance);
    void rotateDegrees(int degrees);

    static Base* getInstance();
};

#endif
