#include "main.h"

Claw* Claw::instance = 0;

Claw::Claw() {
}

void Claw::setClaw(bool isOn) {
  digitalWrite(clawPneumatic, isOn);
}

Claw* Claw::getInstance()
{
    if (instance == 0)
    {
        instance = new Claw();
    }

    return instance;
}
