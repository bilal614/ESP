#ifndef ITEMPERATURE_H
#define ITEMPERATURE_H

class ITemperature
{
public:
  // Inputs
  virtual int GetTemperature() = 0;
  // Outputsv
  //virtual void SetTemperature(int level) = 0;
  virtual void SetHeater(bool sw1tch) = 0;
};

#endif


