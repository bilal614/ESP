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
  if (centipede.digitalRead(IN_IN3))
  {
    //delay(100);
    if (!centipede.digitalRead(IN_IN3))
    {
      value = true;
    }
  }
  return value;
}

/*
   Set the n-th led on base on the indicatior
*/
void HardwareControl::SetCoin10(byte firstCoin, byte secondCoin, byte thirdCoin)
{
  Strobe();
  SetGroup(0);
  if (firstCoin)
  {
    Serial.println("First coin is pressed");
    SetData(0);
  }
  if (secondCoin)
  {
    Serial.println("First coin is pressed");
    SetData(2);
  }
  if (thirdCoin)
  {
    Serial.println("First coin is pressed");
    SetData(3);
  }
}

boolean HardwareControl::GetCoin50Button()
{
  boolean value = false;
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

void HardwareControl::SetCoin50(int leds)
{
  Strobe();
  SetGroup(1);
  switch ( leds ) {
    case 1:
      SetData(0);
      break;
    case 2:
      SetData(1);
      break;
    case 3:
      SetData(2);
    default:
      break;
  }
}

boolean HardwareControl::GetCoin200Button()
{
  boolean value = false;
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

void HardwareControl::SetCoin200(int leds)
{
  centipede.digitalWrite(OUT_GROUP2, HIGH);
  centipede.digitalWrite(OUT_GROUP1, LOW);
  switch ( leds ) {
    case 1:
      centipede.digitalWrite(OUT_DATAC, LOW);
      centipede.digitalWrite(OUT_DATAB, LOW);
      centipede.digitalWrite(OUT_DATAA, HIGH);
      break;
    case 2:
      centipede.digitalWrite(OUT_DATAC, LOW);
      centipede.digitalWrite(OUT_DATAB, HIGH);
      centipede.digitalWrite(OUT_DATAA, LOW);
      break;
    default:
      break;
  }
}

boolean HardwareControl::GetClearButton()
{
  boolean value = false;
  if (centipede.digitalRead(IN_IN3) && centipede.digitalRead(IN_IN2) && centipede.digitalRead(IN_IN3))
  {
    delay(200);
    if (!centipede.digitalRead(IN_IN3) && !centipede.digitalRead(IN_IN2) && !centipede.digitalRead(IN_IN3))
    {
      value = true;
    }
  }
  return value;
}

void HardwareControl:: ClearCoin10(int leds)
{}
void HardwareControl:: ClearCoin50(int leds)
{}
void HardwareControl:: ClearCoin200(int leds)
{}

boolean HardwareControl::GetStartButton()
{
  return (false);
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

void HardwareControl::SetProgramIndicator(int program)
{
}

void HardwareControl::SetBuzzer()
{
}

boolean HardwareControl::buzzerOn()
{}

void HardwareControl::SetKeySelect(int value)
{
}


void HardwareControl::SetSpeed(char mode)
{
}
boolean HardwareControl::GetLockStatus()
{
  boolean lockStatus = false;
  if(centipede.digitalRead(OUT_KEYSELECT) == LOW)//key select must be low in order to interpret inputs from the switches 
  {
    if(centipede.digitalRead(IN_IN3))
    {
      lockStatus = true;
    }
    else
    {
      lockStatus = false;
    }
  }
  return lockStatus;
}

boolean HardwareControl::GetSoap1()
{
  boolean soap1 = false;
  if(centipede.digitalRead(OUT_KEYSELECT) == LOW)//key select must be low in order to interpret inputs from the switches 
  {
    if(centipede.digitalRead(IN_IN1))
    {
      soap1 = true;
    }
    else
    {
      soap1 = false;
    }
  }
  return soap1;
}
boolean HardwareControl::GetSoap2()
{
  boolean soap2 = false;
  if(centipede.digitalRead(OUT_KEYSELECT) == LOW)//key select must be low in order to interpret inputs from the switches 
  {
    if(centipede.digitalRead(IN_IN2))
    {
      soap2 = true;
    }
    else
    {
      soap2 = false;
    }
  }  
  return soap2;
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
}
void HardwareControl::SetData(int data)
{
  if (data == 0)
  {
    centipede.digitalWrite(OUT_DATAA, HIGH);
    centipede.digitalWrite(OUT_DATAB, LOW);
    centipede.digitalWrite(OUT_DATAC, LOW);
  }
  if (data == 1)
  {
    centipede.digitalWrite(OUT_DATAA, LOW);
    centipede.digitalWrite(OUT_DATAB, HIGH);
    centipede.digitalWrite(OUT_DATAC, LOW);
  }
  if (data == 2)
  {
    centipede.digitalWrite(OUT_DATAA, LOW);
    centipede.digitalWrite(OUT_DATAB, LOW);
    centipede.digitalWrite(OUT_DATAC, HIGH);
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
