#include "main.h"
#include "subsystems/arm.h"

Arm* Arm::instance = 0;

Arm::Arm() {
}

void Arm::moveArm(int speed) {
    motorSet(leftShoulderMotor, -speed);
    motorSet(rightShoulderMotor, speed);
}

Arm* Arm::getInstance()
{
    if (instance == 0)
    {
        instance = new Arm();
    }

    return instance;
}
