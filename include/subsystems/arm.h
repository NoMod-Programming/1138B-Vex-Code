#ifndef _SUBSYSTEMS_ARM_H_
#define _SUBSYSTEMS_ARM_H_

#include "main.h"

class Arm {
  private:
    static Arm* instance;
    Arm();
    int armValue = 0;

    static constexpr float armKp = 0.4;

    int  getArmPotentiometer();
  public:
    void moveArm(int speed);
    static Arm* getInstance();
};

#endif
