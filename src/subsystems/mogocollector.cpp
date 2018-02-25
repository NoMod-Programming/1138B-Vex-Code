#include "main.h"

MogoCollector* MogoCollector::instance = 0;

MogoCollector::MogoCollector() {

}

void MogoCollector::moveCollector(int speed) {
  motorSet(baseCollectorLeft, -speed);
  motorSet(baseCollectorRight, speed);
}

MogoCollector* MogoCollector::getInstance()
{
    if (instance == 0)
    {
        instance = new MogoCollector();
    }

    return instance;
}
