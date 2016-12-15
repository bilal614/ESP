#include "Buzzer.h"

Buzzer::Buzzer(IBuzzer* ibuz)
{
	buzzer = ibuz;
}

void Buzzer::SingleBuzzer(int duration)
{
	buzzer.SetBuzzer(duration);
}

void Buzzer::MultipleBuzzer(int duration, int nrTimes)
{
	for (int i = 0; i < nrTimes; i++)
	{
		buzzer.SetBuzzer(duration);
		if (i != nrTimes - 1) delay(duration);
	}
}

Buzzer::~Buzzer()
{
}
