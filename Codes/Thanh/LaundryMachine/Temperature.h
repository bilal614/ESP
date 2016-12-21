#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "ITemperature.h"

class Temperature
{
  private:
  ITemperature* temp;
  int currentTemperature;
  int desiredTemperature;
  
  public:
  Temperature();
  Temperature(ITemperature* itemp);
  int GetDesired();
  int CheckTemperature();
  void SetTemperature(int value);
  void Poll();
  ~Temperature();
  void setInterface(ITemperature* t); 
};

#endif
