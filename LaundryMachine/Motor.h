#ifndef MOTOR_H
#define MOTOR_H

#include "IMotor.h"

const int Motor_High = 0;
const int Motor_Medium = 1;
const int Motor_Low = 2;
const int Motor_OFF = 2;

class Motor
{
  private:
    IMotor* iMotor;
    boolean Direction;
    int Speed;
  
  public:
    Motor(IMotor *m);
    void Start(int s);
    void Stop();
    int GetSpeed();
    boolean GetDirection();                         //will check if 
    void SetDirection(boolean dir);                 //will check if
    
    ~Motor();
};

#endif

