#include "ArduinoWrapper.h"

#include "StubHardwareControl.h"

StubHardwareControl::StubHardwareControl()
{
}

///***IPROGRAM & ICOIN **///
void StubHardwareControl::Strobe()
{

}
boolean StubHardwareControl::GetCoin10Button()
{
    return true;
}

boolean StubHardwareControl::GetCoin50Button()
{
    return true;
}

boolean StubHardwareControl::GetCoin200Button()
{
    return true;
}

void StubHardwareControl::SetCoin10(unsigned char leds)
{
}

void StubHardwareControl::SetCoin50(unsigned char led)
{

}


void StubHardwareControl::SetCoin200(unsigned char led)
{

}

boolean StubHardwareControl::GetClearButton()
{

}

boolean StubHardwareControl::GetStartButton()
{
 return true;
}

boolean StubHardwareControl::GetProgramButton()
{
  return true;
}

void StubHardwareControl::SetProgramIndicator(int program)
{

}


/***ISOAP AND ILOCK***/
void StubHardwareControl::SetSoap1(boolean On)
{

}

void StubHardwareControl::SetSoap2(boolean On)
{

}

boolean StubHardwareControl::GetSoap1()
{
    return true;
}
boolean StubHardwareControl::GetSoap2()
{
    return true;
}

boolean StubHardwareControl::GetLockStatus()
{
    return true;
}

void StubHardwareControl::SetLockStatus(boolean lock)
{

}
/*IMOTOR AND IWATER**/
void StubHardwareControl::OpenSink()
{

}

void StubHardwareControl::CloseSink()
{

}

void StubHardwareControl::OpenDrain()
{
}

void StubHardwareControl::CloseDrain()
{
}

bool StubHardwareControl::GetWater1()
{
    return true;
}

bool StubHardwareControl::GetWater2()
{
    return true;
}

void StubHardwareControl::TurnLeft()
{

}

void StubHardwareControl::TurnRight()
{

}

void StubHardwareControl::StartSpeed1()
{

}

void StubHardwareControl::StopSpeed1()
{

}

void StubHardwareControl::StartSpeed2()
{

}

void StubHardwareControl::StopSpeed2()
{

}

/**IBUZZER AND ITEMPERTURE**/

void StubHardwareControl::SetBuzzer(int ms)
{

}
int StubHardwareControl::GetTemperature()
{
  int c = 0;

  return c;
}

/**
   Attention! Heater turns on when sw1tch == true
*/
void StubHardwareControl::SetHeater(bool sw1tch)
{
}






/**HARDWARE CONTROL PRIVATE FUNCTIONS*/
void StubHardwareControl::SetGroup(int group)
{

}

void StubHardwareControl::SetData(int data)
{


}
void StubHardwareControl::SetKeySelect(int value)
{

}
