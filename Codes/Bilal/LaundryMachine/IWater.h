#ifndef IWATER_H
#define IWATER_H

class IWater
{
public:
  // Inputs

  // Outputs
  virtual void SetDrain(int level) = 0;
  virtual void SetWaterLevel(int level) = 0;
  virtual bool CheckWaterLevel() = 0;
  virtual void SinkWater() = 0;
  
};

#endif


