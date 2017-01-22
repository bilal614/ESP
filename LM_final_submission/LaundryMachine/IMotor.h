#ifndef IMOTOR_H
#define IMOTOR_H

class IMotor
{
    public:
    // Outputs
      virtual void TurnLeft() = 0;
      virtual void TurnRight() = 0;
      virtual void StartSpeed1() = 0;
      virtual void StartSpeed2() = 0; 
      virtual void StopSpeed1() = 0;
      virtual void StopSpeed2() = 0;
};

#endif


