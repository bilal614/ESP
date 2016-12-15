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
	Temperature(ITemperature*);
	int GetDesired();
	int CheckTemperature();
	void SetTemperature();
	void Poll();
	~Temperature();	
}

#endif