#include "Temperature.h"

Temperature::Temperature()
{
}

Temperature::Temperature(ITemperature* itemp)
{
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
  currentTemperature = itemp.GetTemperature();
  if (desiredTemperature == 3) itemp.SetHeater(true);
  else if (desiredTemperature == 0) itemp.SetHeater(false);
  else
  {
    if (desiredTemperature > currentTemperature) itemp.SetHeater(true);
    else if (desiredTemperature < currentTemperature) itemp.SetHeater(false);
    else
    {
      itemp.SetHeater(true);
      delay(100);
      itemp.SetHeater(false);
      delay(90);
    }
  }
}

Temperature::~Temperature()
{
}
