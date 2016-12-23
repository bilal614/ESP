
#include "Motor.h"

Motor::Motor(IMotor * m)
{
  iMotor = m;
}

void Motor::Start(int s)
{
  switch (s)
  {
    case Low:
      iMotor->StartSpeed1();
      iMotor->StopSpeed2();
      break;
    case Medium:
      iMotor->StartSpeed1();
      iMotor->StopSpeed2();
      break;
    case High:
      iMotor->StartSpeed1();
      iMotor->StartSpeed2();
      break;
    default:
      //Print error message and turn motor off
      //Serial.println("The speed entered should be between 1 and 3."); // or cout<<"Message"<<endl;
      iMotor->StopSpeed1();
      iMotor->StopSpeed2();
      break;
  }
}

void Motor::Stop()
{
  iMotor->StopSpeed1();
  iMotor->StopSpeed2();
}

void Motor::SetDirection(boolean dir)  // 0 for LEFT and 1 for RIGHT
{
  if (dir)
  {
    iMotor->TurnRight();
  }
  else
  {
    iMotor->TurnLeft();
  }
}

Motor::~Motor()
{
  //delete iMotor;
}

