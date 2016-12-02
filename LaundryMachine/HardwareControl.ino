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
  Serial.println("Construtor is called");
}

///***IPROGRAM & ICOIN **///
void HardwareControl::Strobe()
{
  //Serial.println("Strobe is called");
  centipede.digitalWrite(OUT_STROBE, LOW);
  delay(85);
  centipede.digitalWrite(OUT_STROBE, HIGH);
  delay(15);
}
boolean HardwareControl::GetCoin10Button()
{
  boolean value = false;
  centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  if (centipede.digitalRead(IN_IN3))
  {
    delay(100);
    if (!centipede.digitalRead(IN_IN3))
    {
      value = true;
    }
  }
  return value;
}

/*
   leds is indicator which LED will be turn on
   eg. Call SetCoin10(B00000111) means 3 coins 10 is added
*/
void HardwareControl::SetCoin10(byte leds)
{
  Strobe();
  SetGroup(0);
  SetData(leds);
}

boolean HardwareControl::GetCoin50Button()
{
  boolean value = false;
 SetKeySelect(1);
  if (centipede.digitalRead(IN_IN2))
  {
    delay(100);
    if (!centipede.digitalRead(IN_IN2))
    {
      value = true;
    }
  }
  return value;
}

void HardwareControl::SetCoin50(byte led)
{
  Strobe();
  SetGroup(1);
  SetData(led);
}

boolean HardwareControl::GetCoin200Button()
{
  boolean value = false;
  SetKeySelect(1);
  if (centipede.digitalRead(IN_IN1))
  {
    delay(200);
    if (!centipede.digitalRead(IN_IN1))
    {
      value = true;
    }
  }
  return value;
}

void HardwareControl::SetCoin200(byte led)
{
  Strobe();
  SetGroup(2);
  SetData(led);
}

boolean HardwareControl::GetClearButton()
{
  boolean value = false;
  SetKeySelect(1);
  //keep pressing until all LED is clear
  if (centipede.digitalRead(IN_IN3) && centipede.digitalRead(IN_IN2) && centipede.digitalRead(IN_IN3))
  {
    value = true;
  }
  return value;
}


boolean HardwareControl::GetStartButton()
{
  boolean value = false;
  SetKeySelect(1);
  if (centipede.digitalRead(IN_IN0))
  {
    delay(200);
    if (!centipede.digitalRead(IN_IN0))
    {
      value = true;
    }
  }
  return value;
}

boolean HardwareControl::GetProgramButton()
{
  boolean value = false;
  SetKeySelect(1);
  if (centipede.digitalRead(IN_IN0) | centipede.digitalRead(IN_IN3))
  {
    delay(200);
    if (!centipede.digitalRead(IN_IN0) | !centipede.digitalRead(IN_IN3))
    {
      value = true;
    }
  }
  return value;
}

void HardwareControl::SetProgramIndicator(int program)
{
  Strobe();
  SetGroup(3);
  SetData(program);
}


int HardwareControl::GetTemperature()
{
  return (0);
}

void HardwareControl::SetSoap1(boolean On)
{
  if (On)
  {
    centipede.digitalWrite(OUT_SOAP1, HIGH);
  }
  if (!On)
  {
    centipede.digitalWrite(OUT_SOAP1, LOW);
  }
}

void HardwareControl::SetSoap2(boolean On)
{
  if (On)
  {
    centipede.digitalWrite(OUT_GROUP2, HIGH); centipede.digitalWrite(OUT_DATAC, HIGH);
  }
  if (!On)
  {
    centipede.digitalWrite(OUT_GROUP2, LOW); centipede.digitalWrite(OUT_DATAC, LOW);
  }
}

void HardwareControl::SetDrain(int level)
{
}

void HardwareControl::SetDirection(int dir)
{
}


void HardwareControl::SetBuzzer()
{
}

boolean HardwareControl::buzzerOn()
{}




void HardwareControl::SetSpeed(char mode)
{
}
boolean HardwareControl::GetLockStatus()
{
  if (centipede.digitalRead(OUT_KEYSELECT) == LOW) //key select must be low in order to interpret inputs from the switches
  {
    if (centipede.digitalRead(IN_IN3))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

/*Added LockDoor & UnlockDoor for removing "undifined reference" errors*/
boolean HardwareControl::LockDoor(boolean &lockStatus) {}
boolean HardwareControl::UnlockDoor(boolean &lockStatus) {}
boolean HardwareControl::GetSoap1()
{
  if (centipede.digitalRead(OUT_KEYSELECT) == LOW) //key select must be low in order to interpret inputs from the switches
  {
    if (centipede.digitalRead(IN_IN1))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}
boolean HardwareControl::GetSoap2()
{
  if (centipede.digitalRead(OUT_KEYSELECT) == LOW) //key select must be low in order to interpret inputs from the switches
  {
    if (centipede.digitalRead(IN_IN2))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}
void HardwareControl::SetGroup(int group)
{
  if (group == 0)
  {
    centipede.digitalWrite(OUT_GROUP1, LOW);
    centipede.digitalWrite(OUT_GROUP2, LOW);
  }
  if (group == 1)
  {
    centipede.digitalWrite(OUT_GROUP1, HIGH);
    centipede.digitalWrite(OUT_GROUP2, LOW);
  }
  if (group == 2)
  {
    centipede.digitalWrite(OUT_GROUP1, LOW);
    centipede.digitalWrite(OUT_GROUP2, HIGH);
  }
  if (group == 3)
  {
    centipede.digitalWrite(OUT_GROUP1, HIGH);
    centipede.digitalWrite(OUT_GROUP2, HIGH);
  }
}
void HardwareControl::SetData(int data)
{

  switch (data) {
    case B00000000:
      centipede.digitalWrite(OUT_DATAA, LOW);
      centipede.digitalWrite(OUT_DATAB, LOW);
      centipede.digitalWrite(OUT_DATAC, LOW);
      break;
    case B00000001:
      centipede.digitalWrite(OUT_DATAA, HIGH);
      centipede.digitalWrite(OUT_DATAB, LOW);
      centipede.digitalWrite(OUT_DATAC, LOW);
      break;
    case B00000010:
      centipede.digitalWrite(OUT_DATAA, LOW);
      centipede.digitalWrite(OUT_DATAB, HIGH);
      centipede.digitalWrite(OUT_DATAC, LOW);
      break;
    case B00000100:
      centipede.digitalWrite(OUT_DATAA, LOW);
      centipede.digitalWrite(OUT_DATAB, LOW);
      centipede.digitalWrite(OUT_DATAC, HIGH);
      break;
    case B00000011:
      centipede.digitalWrite(OUT_DATAA, HIGH);
      centipede.digitalWrite(OUT_DATAB, HIGH);
      centipede.digitalWrite(OUT_DATAC, LOW);
      break;
    case B00000110:
      centipede.digitalWrite(OUT_DATAA, LOW);
      centipede.digitalWrite(OUT_DATAB, HIGH);
      centipede.digitalWrite(OUT_DATAC, HIGH);
      break;
    case B00000101:
      centipede.digitalWrite(OUT_DATAA, HIGH);
      centipede.digitalWrite(OUT_DATAB, LOW);
      centipede.digitalWrite(OUT_DATAC, HIGH);
      break;
    case B00000111:
      centipede.digitalWrite(OUT_DATAA, HIGH);
      centipede.digitalWrite(OUT_DATAB, HIGH);
      centipede.digitalWrite(OUT_DATAC, HIGH);
      break;
    default:
      break;
  }
}
void HardwareControl::SetKeySelect(int value)
{
  if(value == 1)
  {
    centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  }
  else
  {
    centipede.digitalWrite(OUT_KEYSELECT, LOW);
  }
}
void HardwareControl::SetAndTrackTime() {}
void HardwareControl::CheckLoadingLevel(int level) {}
void HardwareControl::StartMotor() {}
void HardwareControl::StopMotor() {}
void HardwareControl::IncreaseTemperature() {}
void HardwareControl::DecreaseTemperature() {}
void HardwareControl::SetWaterLevel(int level) {}
bool HardwareControl::CheckWaterLevel() {}
void HardwareControl::SinkWater() {}
