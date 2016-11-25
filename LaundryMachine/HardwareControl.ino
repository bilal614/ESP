#define OUT_GROUP2      0
#define OUT_GROUP1      1
#define OUT_STROBE      2
#define OUT_KEYSELECT   3
#define OUT_BUZZER      4
#define OUT_HEATER      5
#define OUT_SPEED2      6
#define OUT_SPEED1      7
#define OUT_DATAC       8
#define OUT_DATAB       9
#define OUT_DATAA       10
#define OUT_MOTOR_RL    11
#define OUT_SOAP1       12
#define OUT_SINK        13
#define OUT_DRAIN       14
#define OUT_LOCK        15
#define IN_W2           16
#define IN_W1           17
#define IN_T2           18
#define IN_T1           19
#define IN_IN3          20
#define IN_IN2          21
#define IN_IN1          22
#define IN_IN0          23

HardwareControl::HardwareControl()
{
  Wire.begin(); // start I2C
  centipede.initialize(); // set all registers to default
  for (int i = 0; i <= 15; i++) 
  {
    centipede.pinMode(i, OUTPUT);
  }
  centipede.digitalWrite(OUT_GROUP2, LOW);
  centipede.digitalWrite(OUT_GROUP1, LOW);
  centipede.digitalWrite(OUT_STROBE, LOW);
  centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  centipede.digitalWrite(OUT_BUZZER, HIGH);
  centipede.digitalWrite(OUT_HEATER, HIGH);
  centipede.digitalWrite(OUT_SPEED2, HIGH);
  centipede.digitalWrite(OUT_SPEED1, HIGH);
  centipede.digitalWrite(OUT_DATAC, LOW);
  centipede.digitalWrite(OUT_DATAB, LOW);
  centipede.digitalWrite(OUT_DATAA, LOW);
  centipede.digitalWrite(OUT_MOTOR_RL, LOW);
  centipede.digitalWrite(OUT_SOAP1, LOW);
  centipede.digitalWrite(OUT_SINK, LOW);
  centipede.digitalWrite(OUT_DRAIN, LOW);
  centipede.digitalWrite(OUT_LOCK, LOW);
}

///***IPROGRAM & ICOIN **///
boolean HardwareControl::GetCoin10Button()
{
  int dataA = centipede.digitalRead(OUT_DATAA);
  int dataB = centipede.digitalRead(OUT_DATAB);
  int dataC = centipede.digitalRead(OUT_DATAC);
  int group1 = centipede.digitalRead(OUT_GROUP1);
  int group2 = centipede.digitalRead(OUT_GROUP2);
  
  if(dataA == 0 && dataB == 0 && dataC == 1 && group1 == 0 && group2 == 0)
  {
    return true;
  }
  return false;
}

void HardwareControl::SetCoin10(int leds)
{
  centipede.digitalWrite(leds, HIGH);
}

boolean HardwareControl::GetCoin50Button()
{
  int dataA = centipede.digitalRead(OUT_DATAA);
  int dataB = centipede.digitalRead(OUT_DATAB);
  int dataC = centipede.digitalRead(OUT_DATAC);
  if(dataA == 0 && dataB == 0 && dataC == 1)
  {
    return true;
  }
  return false;
}

void HardwareControl::SetCoin50(int leds)
{
  
}

boolean HardwareControl::GetCoin200Button()
{
  int dataA = centipede.digitalRead(OUT_DATAA);
  int dataB = centipede.digitalRead(OUT_DATAB);
  int dataC = centipede.digitalRead(OUT_DATAC);
  if(dataA == 0 && dataB == 0 && dataC == 1)
  {
    return true;
  }
  return false;
}

void HardwareControl::SetCoin200(int leds)
{
  
}

boolean HardwareControl::GetStartButton()
{
  return (false);
}

int HardwareControl::GetTemperature()
{
  return (0);
}




void HardwareControl::SetSoap2(int level)
{
}

void HardwareControl::SetDrain(int level)
{
}

void HardwareControl::SetDirection(int dir)
{
}

void HardwareControl::SetProgramIndicator(int program)
{
}

void HardwareControl::SetBuzzer(int level)
{
}

void HardwareControl::SetKeySelect(int value)
{
}

void HardwareControl::SetGroup(int group)
{
}

void HardwareControl::SetData(int data)
{
}

void HardwareControl::Strobe()
{
}



