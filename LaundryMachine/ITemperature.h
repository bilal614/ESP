#ifndef ITEMPERATURE_H
#define ITEMPERATURE_H

class ITemperature
{
public:
  // Inputs
  virtual int GetTemperature() = 0;
  // Outputs
  virtual void IncreaseTemperature() = 0;
  virtual void DecreaseTemperature() = 0;
};

#endif


