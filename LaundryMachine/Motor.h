#ifndef MOTOR_H
#define MOTOR_H

#include "IMotor.h"

const int High = 3;
const int Medium = 2;
const int Low = 1;
const int OFF = 0;

class Motor
{
  private:
    IMotor* oMotor;
    boolean Direction;
    int Speed;

  public:
    Motor(IMotor *);
    void Start(int s);
    void Stop();
    void SetDirection(boolean dir);
    ~Motor();
};

#endif

