#ifndef IWATER_H
#define IWATER_H

class IWater
{
public:
  // Inputs

  // Outputs
  virtual void SetWaterLevel(int level) = 0;
  virtual boolean CheckWaterLevel(int level) = 0;
  virtual void SinkWater() = 0;
  
};

#endif


