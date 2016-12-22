#include "Motor.h"

Motor::Motor(IMotor * m)
{
  iMotor = m;
}

void Motor::Start(int s)
{}

void Motor::Stop()
{}

int Motor::GetSpeed()
{
  return 0;
}
  
boolean Motor::GetDirection()
{
  return false;
}
  
void Motor::SetDirection(boolean dir)
{}    

Motor::~Motor()
{
  //delete iMotor;  
}

