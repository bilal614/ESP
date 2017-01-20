#include "Motor.h"

Motor::Motor()
{
  Direction = 1;
  Speed = 0;  
}

Motor::Motor(IMotor * m)
{
  oMotor = m;
}

void Motor::Start(int s)
{
  switch (s)
  {
    case Low:
      oMotor->StartSpeed1();
      oMotor->StopSpeed2();
      break;
    case Medium:
      oMotor->StartSpeed1();
      oMotor->StopSpeed2();
      break;
    case High:
      oMotor->StartSpeed1();
      oMotor->StartSpeed2();
      break;
    default:
      //Print error message and turn motor off
      Serial.println("The speed entered should be between 1 and 3."); delay(1000);// or cout<<"Message"<<endl;
      oMotor->StopSpeed1();
      oMotor->StopSpeed2();
      break;
  }
}

void Motor::Stop()
{
  oMotor->StopSpeed1();
  oMotor->StopSpeed2();
  
  Serial.println("stop has occurred");
}

void Motor::SetDirection(boolean dir)  // 0 for LEFT and 1 for RIGHT
{
  if (dir)
  {
    oMotor->TurnRight();
  }
  else
  {
    oMotor->TurnLeft();
  }
}

Motor::~Motor()
{
  //delete oMotor;
}

void Motor::rotateLM(boolean dir, int Speed)
{
  SetDirection(dir); 
  Serial.println("direction is set");
  Start(Speed);
  Serial.println("speed is set");
  //delay(duration);
  //Stop();
  Serial.println("one step ended");
}

void Motor::Centrifugation()//open sink before calling this function
{
  int count = 0; 
  do{
    SetDirection(1);
    Start(High);
    delay(3000);
    Stop();
    SetDirection(0);
    Start(High);
    delay(3000);
    Stop();
    count++;
  }while(count <2);
}

void Motor::setInterface(IMotor* m)
{
  oMotor = m;  
}


