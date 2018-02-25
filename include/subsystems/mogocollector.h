#ifndef _SUBSYSTEMS_MOGOCOLLECTOR_H_
#define _SUBSYSTEMS_MOGOCOLLCETOR_H_

#include "main.h"

class MogoCollector {
  private:
    static MogoCollector* instance;
    MogoCollector();
  public:
    void moveCollector(int speed);

    static MogoCollector* getInstance();
};

#endif
