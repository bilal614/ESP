#ifndef ITEMPERATURE_H
#define ITEMPERATURE_H

class ITemperature
{
public:
  // Inputs
  virtual int GetTemperature() = 0;
  // Outputsv
  virtual void SetHeater(bool switch) = 0;
};

#endif


