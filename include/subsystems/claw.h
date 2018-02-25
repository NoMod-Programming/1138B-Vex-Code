#ifndef _SUBSYSTEMS_CLAW_H_
#define _SUBSYSTEMS_CLAW_H_

class Claw {
  private:
    Claw();
    static Claw* instance;
  public:
    void setClaw(bool isOn);
    static Claw* getInstance();
};

#endif
