#include "main.h"

Base* Base::instance = 0;

Base::Base() {
  gyro = gyroInit(gyroSensor, 196);
}

void Base::moveBase(int leftSpeed, int rightSpeed) {
  motorSet(leftFrontMotor, leftSpeed);
  motorSet(leftBackMotor, -leftSpeed);
  motorSet(rightFrontMotor, -rightSpeed);
  motorSet(rightBackMotor, rightSpeed);
}

void Base::moveTo(int inches) {
  int leftSpeed;
  int rightSpeed;

  // Reset IMEs. Move this to a different function in the future
  imeReset(0);
  imeReset(1);
  gyroReset(gyro);

  int distance = inches * rotationsPerInch;
  while (abs(getRightIME()) < abs(distance)) {
    leftSpeed = leftKp * (distance - getLeftIME());
    leftSpeed -= 5 * (gyroGet(gyro));
    rightSpeed = rightKp * (distance - getRightIME());
    rightSpeed += 5 * (gyroGet(gyro));
    moveBase(leftSpeed, rightSpeed);
  }
  moveBase(0, 0);
}

void Base::rotateDegrees(int degrees) {
  gyroReset(gyro);
  int leftSpeed;
  int rightSpeed;
  while (abs(gyroGet(gyro)) < abs(degrees)) {
    leftSpeed = leftKp * (degrees - gyroGet(gyro));
    rightSpeed = rightKp * (gyroGet(gyro) - degrees);
    moveBase(leftSpeed, rightSpeed);
  }
}

int Base::getLeftIME() {
  int count;
  imeGet(0, &count);
  return count;
}

int Base::getRightIME() {
  int count;
  imeGet(1, &count);
  return count;
}

Base* Base::getInstance()
{
    if (instance == 0)
    {
        instance = new Base();
    }

    return instance;
}
