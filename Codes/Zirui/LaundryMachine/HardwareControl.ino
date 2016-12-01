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
boolean HardwareControl::GetCoin10Button()
{

  if (centipede.digitalRead(IN_IN3))
  {
    return true;
  }
  else
    return false;
}

/*
   Set the nr of leds on based on the nr of coins
*/
void HardwareControl::SetCoin10(int leds)
{
  centipede.digitalWrite(OUT_GROUP2, LOW);
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
    case 3:
      centipede.digitalWrite(OUT_DATAC, HIGH);
      centipede.digitalWrite(OUT_DATAB, LOW);
      centipede.digitalWrite(OUT_DATAA, LOW);
    default:
      break;
  }
}

boolean HardwareControl::GetCoin50Button()
{
  if (centipede.digitalRead(IN_IN2))
  {
    return true;
  }
  else
    return false;
}

void HardwareControl::SetCoin50(int leds)
{
  centipede.digitalWrite(OUT_GROUP2, LOW);
  centipede.digitalWrite(OUT_GROUP1, HIGH);
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
    case 3:
      centipede.digitalWrite(OUT_DATAC, HIGH);
      centipede.digitalWrite(OUT_DATAB, LOW);
      centipede.digitalWrite(OUT_DATAA, LOW);
    default:
      break;
  }
}

boolean HardwareControl::GetCoin200Button()
{
  if (centipede.digitalRead(IN_IN1))
  {
    return true;
  }
  else
    return false;
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
  if (centipede.digitalRead(IN_IN3) && centipede.digitalRead(IN_IN2) && centipede.digitalRead(IN_IN3))
  {
    return true;
  }
  else
  {
    return false;
  }
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

void HardwareControl::SetBuzzer()
{
}

boolean HardwareControl::buzzerOn()
{}

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

boolean HardwareControl:: LockDoor(boolean &lockStatus)
{
}
boolean HardwareControl:: UnlockDoor(boolean &lockStatus)
{
}
boolean HardwareControl::LockSoapCpt()
{
}
boolean HardwareControl::UnlockSoapCpt()
{
}
void HardwareControl::SetSpeed(char mode)
{
}
boolean HardwareControl::GetLockStatus(){}
boolean HardwareControl::GetSoapCptStatus(){}
void HardwareControl::SetAndTrackTime() {}
void HardwareControl::CheckLoadingLevel(int level) {}
void HardwareControl::StartMotor() {}
void HardwareControl::StopMotor() {}

void HardwareControl::SetTemperature(int level) 
{
  centipede.digitalWrite(IN_T1, (level & 0x01));
  centipede.digitalWrite(IN_T2, (level & 0x02));
}

void HardwareControl::SetWaterLevel(int level) {}
bool HardwareControl::CheckWaterLevel() {}
void HardwareControl::SinkWater() {}
