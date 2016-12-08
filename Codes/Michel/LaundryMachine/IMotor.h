#ifndef IMOTOR_H
#define IMOTOR_H

class IMotor
{
public:
  // Outputs
  virtual void SetDirection(char dir) = 0;
  virtual void SetSpeed(int level) = 0;
  virtual boolean CheckLoadingLevel(int level) = 0;
  
  virtual void StartMotor() = 0;  
  virtual void StopMotor() = 0;
};

#endif


