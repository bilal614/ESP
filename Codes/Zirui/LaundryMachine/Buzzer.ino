#include "Buzzer.h"

Buzzer::Buzzer()
{
}

Buzzer::Buzzer(IBuzzer* ibuz)
{
}

void Buzzer::SingleBuzzer(int duration)
{
	ibuz.SetBuzzer(duration);
}

void Buzzer::MultipleBuzzer(int duration, int nrTimes)
{
	for (int i = 0; i < nrTimes; i++)
	{
		ibuz.SetBuzzer(duration);
		if (i != nrTimes - 1) delay(duration);
	}
}

Buzzer::~Buzzer()
{
}
