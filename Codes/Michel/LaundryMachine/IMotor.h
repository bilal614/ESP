#ifndef IMOTOR_H
#define IMOTOR_H

class IMotor
{
public:
  // Outputs
  virtual void SetDirection(int dir) = 0;
  virtual void SetSpeed(char mode) = 0;  
  virtual void SetAndTrackTime()= 0;
  virtual void CheckLoadingLevel(int level) = 0;
  
  virtual void StartMotor() = 0;  
  virtual void StopMotor() = 0;
};

#endif


