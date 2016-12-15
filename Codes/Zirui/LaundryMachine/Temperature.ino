#include "Temperature.h"

Temperature::Temperature(ITemperature* itemp)
{
	temp = itemp;
}

int Temperature::GetDesired()
{
	return desiredTemperature;
}

int Temperature::CheckTemperature()
{
	return currentTemperature;
}

void Temperature::SetTemperature(int value)
{
	desiredTemperature = value;
}

void Temperature::Poll()
{
  currentTemperature = temp.GetTemperature();
  if (desiredTemperature == 3) temp.SetHeater(true);
  else if (desiredTemperature == 0) temp.SetHeater(false);
  else
  {
    if (desiredTemperature > currentTemperature) temp.SetHeater(true);
    else if (desiredTemperature < currentTemperature) temp.SetHeater(false);
    else
    {
      temp.SetHeater(true);
      delay(100);
      temp.SetHeater(false);
      delay(90);
    }
  }
}

Temperature::~Temperature()
{
}
