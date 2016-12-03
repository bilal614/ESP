#ifndef ITEMPERATURE_H
#define ITEMPERATURE_H

class ITemperature
{
public:
  // Inputs
  // Outputsv
  virtual int GetTemperature() = 0;
  virtual void SetTemperature(int level) = 0;
};

#endif


