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
  //Serial.println("Construtor is called");
}

///***IPROGRAM & ICOIN **///
void HardwareControl::Strobe()
{
  //Serial.println("Strobe is called");
  centipede.digitalWrite(OUT_STROBE, LOW);
  delay(80);
  centipede.digitalWrite(OUT_STROBE, HIGH);
  delay(10);
}
boolean HardwareControl::GetCoin10Button()
{
  boolean value = false;
  centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  if (centipede.digitalRead(IN_IN3) && !centipede.digitalRead(IN_IN2) && !centipede.digitalRead(IN_IN1) && !centipede.digitalRead(IN_IN0))
  {
    delay(200);
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
  if (centipede.digitalRead(IN_IN2) && !centipede.digitalRead(IN_IN1) && !centipede.digitalRead(IN_IN3) && !centipede.digitalRead(IN_IN0))
  {
    value = true;
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
  if (centipede.digitalRead(IN_IN1) && !centipede.digitalRead(IN_IN3) && !centipede.digitalRead(IN_IN2) && !centipede.digitalRead(IN_IN0))
  {
    value = true;
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
  if (centipede.digitalRead(IN_IN3) && centipede.digitalRead(IN_IN2) && centipede.digitalRead(IN_IN1) && !centipede.digitalRead(IN_IN0))
  {
    value = true;
  }
  return value;
}


boolean HardwareControl::GetStartButton()
{
  boolean value = false;
  SetKeySelect(1);
  if (centipede.digitalRead(IN_IN0) && !centipede.digitalRead(IN_IN3) && !centipede.digitalRead(IN_IN2) && !centipede.digitalRead(IN_IN1) )
  {
    value = true;
  }
  return value;
}

boolean HardwareControl::GetProgramButton()
{
  boolean value = false;
  SetKeySelect(1);
  if (centipede.digitalRead(IN_IN0) && centipede.digitalRead(IN_IN3) && !centipede.digitalRead(IN_IN1) && !centipede.digitalRead(IN_IN2))
  {
      value = true;
  }
  return value;
}

void HardwareControl::SetProgramIndicator(int program)
{
  Strobe();
  SetGroup(3);
  SetData(program);
}

/*
void HardwareControl::SetTemperature(int level)
{
  centipede.digitalWrite(IN_T1, (level & 0x01));
  centipede.digitalWrite(IN_T2, (level & 0x02));
}
*/

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
  Strobe();
  SetGroup(2);//to make group2 high and group1 low
  if (On)
  {
    centipede.digitalWrite(OUT_DATAC, HIGH);
  }
  if (!On)
  {
    centipede.digitalWrite(OUT_DATAC, LOW);
  }
}

void HardwareControl::SetDirection(char dir)
{
  switch (dir)
  {
    case 'L':
      // L for left
      centipede.digitalWrite(OUT_MOTOR_RL, LOW);
      break;
    case 'R':
      // R for right
      centipede.digitalWrite(OUT_MOTOR_RL, HIGH);
      break;
    default:
      break;
  }
}


void HardwareControl::SetBuzzer(int ms)
{
}

void HardwareControl::SetSpeed(int level)
{
  switch (level)
  {
    case 1:
      // level = 1 is for low
      centipede.digitalWrite(OUT_SPEED2, HIGH);
      centipede.digitalWrite(OUT_SPEED1, LOW);
      break;
    case 2:
      // level = 2 is for medium
      centipede.digitalWrite(OUT_SPEED2, LOW);
      centipede.digitalWrite(OUT_SPEED1, HIGH);
      break;
    case 3:
      // level = 3 is for high
      centipede.digitalWrite(OUT_SPEED2, LOW);
      centipede.digitalWrite(OUT_SPEED1, LOW);
      break;
    default:
      break;
  }
}
boolean HardwareControl::GetLockStatus()
{
  centipede.digitalWrite(OUT_KEYSELECT, LOW);
  boolean lockStatus = false;
  if (centipede.digitalRead(OUT_KEYSELECT) == LOW) //key select must be low in order to interpret inputs from the switches
  {
    if (centipede.digitalRead(IN_IN3))
    {
      lockStatus = true;
    }
    else
    {
      lockStatus = false;
    }
  }
}
void HardwareControl::SetLockStatus(boolean lock)
{
  if (lock)
  {
    centipede.digitalWrite(OUT_LOCK, HIGH);
  }
  if (!lock)
  {
    centipede.digitalWrite(OUT_LOCK, LOW);
  }

}

boolean HardwareControl::GetSoap1()
{
  centipede.digitalWrite(OUT_KEYSELECT, LOW);
  boolean soap1 = false;
  if (centipede.digitalRead(OUT_KEYSELECT) == LOW) //key select must be low in order to interpret inputs from the switches
  {
    if (centipede.digitalRead(IN_IN1))
    {
      HardwareControl::SetSoap1(true);
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
  centipede.digitalWrite(OUT_KEYSELECT, LOW);
  boolean soap2 = false;
  if (centipede.digitalRead(OUT_KEYSELECT) == LOW) //key select must be low in order to interpret inputs from the switches
  {
    if (centipede.digitalRead(IN_IN2))
    {
      HardwareControl::SetSoap2(true);
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
  if (value == 1)
  {
    centipede.digitalWrite(OUT_KEYSELECT, HIGH);
  }
  else
  {
    centipede.digitalWrite(OUT_KEYSELECT, LOW);
  }
}
void HardwareControl::CheckLoadingLevel(int level)
{
  switch (level)
  {
    case 1:
      // level = 1 is for 33%
      if (centipede.digitalRead(IN_W2) == LOW && centipede.digitalRead(IN_W1) == HIGH)
      {
        return true;
      }
      else
      {
        return false;
      }
      break;
    case 2:
      // level = 2 is for 66%
      if (centipede.digitalRead(IN_W2) == HIGH && centipede.digitalRead(IN_W1) == LOW)
      {
        return true;
      }
      else
      {
        return false;
      }
      break;
    case 3:
      // level = 3 is for 100%
      if (centipede.digitalRead(IN_W2) == HIGH && centipede.digitalRead(IN_W1) == HIGH)
      {
        return true;
      }
      else
      {
        return false;
      }
      break;
    default:
      // No water in the machine
      return false;
      break;
  }
}
void HardwareControl::StartMotor()
{
  HardwareControl::SetSpeed(1);
}

void HardwareControl::StopMotor()
{
  // Turn motor OFF
  centipede.digitalWrite(OUT_SPEED2, HIGH);
  centipede.digitalWrite(OUT_SPEED1, HIGH);
}

void HardwareControl::SetWaterLevel(int level)
{
  if (level == 1)                       //Filled at 33%
  {
    while (centipede.digitalRead(IN_W2) != LOW && centipede.digitalRead(IN_W1) != HIGH)
    {
      centipede.digitalWrite(OUT_SINK, LOW);
      centipede.digitalWrite(OUT_DRAIN, HIGH);
    }
  }
  else if (level == 2)                  //Filled at 66%
  {
    while (centipede.digitalRead(IN_W2) != HIGH && centipede.digitalRead(IN_W1) != LOW)
    {
      centipede.digitalWrite(OUT_SINK, LOW);
      centipede.digitalWrite(OUT_DRAIN, HIGH);
    }
  }
  else if (level == 3)                  //Filled at 100%
  {
    while (centipede.digitalRead(IN_W2) != HIGH && centipede.digitalRead(IN_W1) != HIGH)
    {
      centipede.digitalWrite(OUT_SINK, LOW);
      centipede.digitalWrite(OUT_DRAIN, HIGH);
    }
  }
  else                                 // Fixed Level
  {
    centipede.digitalWrite(OUT_SINK, HIGH);
    centipede.digitalWrite(OUT_DRAIN, HIGH);
  }
}
bool HardwareControl::CheckWaterLevel(int level)
{
  switch (level)
  {
    case 1:
      // level = 1 is for 33%
      if (centipede.digitalRead(IN_W2) == LOW && centipede.digitalRead(IN_W1) == HIGH)
      {
        return true;
      }
      else
      {
        return false;
      }
      break;
    case 2:
      // level = 2 is for 66%
      if (centipede.digitalRead(IN_W2) == HIGH && centipede.digitalRead(IN_W1) == LOW)
      {
        return true;
      }
      else
      {
        return false;
      }
      break;
    case 3:
      // level = 3 is for 100%
      if (centipede.digitalRead(IN_W2) == HIGH && centipede.digitalRead(IN_W1) == HIGH)
      {
        return true;
      }
      else
      {
        return false;
      }
      break;
    default:
      // No water in the machine
      return false;
      break;
  }
}
void HardwareControl::SinkWater()
{
  while (centipede.digitalRead(IN_W2) != LOW || centipede.digitalRead(IN_W1) != LOW)
  {
    centipede.digitalWrite(OUT_SINK, HIGH);
    centipede.digitalWrite(OUT_DRAIN, LOW);
  }
}

void HardwareControl::SetHeater(bool sw1tch)
{
  centipede.digitalWrite(OUT_HEATER, !sw1tch);
}

int HardwareControl::GetTemperature() 
{
  int c = 0;
  if (centipede.digitalRead(IN_T2) == HIGH) c += 2;  
  if (centipede.digitalRead(IN_T1) == HIGH) c += 1;
  return c;
}

