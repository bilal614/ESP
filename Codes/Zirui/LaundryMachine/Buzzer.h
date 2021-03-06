#ifndef BUZZER_H
#define BUZZER_H

#include "IBuzzer.h"

class Buzzer
{
	private:
	IBuzzer* buzzer;
	
	public:
	Buzzer(IBuzzer* ibuz);
	void SingleBuzzer(int duration);
	void MultipleBuzzer(int duration, int nrTimes);
	~Buzzer();	
}

#endif