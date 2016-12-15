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
}

Temperature::~Temperature()
{
}
