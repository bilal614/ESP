Temperature::Temperature()
{
  desiredTemperature = 0;
}

Temperature::Temperature(ITemperature* itemp)
{
  Temp = itemp;
  desiredTemperature = 0;
}

int Temperature::GetDesired()
{
  return desiredTemperature;
}

int Temperature::CheckTemperature()
{
  return currentTemperature;
}

void Temperature::SetTemperature(int value)
{
  desiredTemperature = value;
}

void Temperature::Poll()
{
  currentTemperature = Temp->GetTemperature();
  if (desiredTemperature == 3) Temp->SetHeater(true);
  else if (desiredTemperature == 0) Temp->SetHeater(false);
  else
  {
    if (desiredTemperature > currentTemperature) Temp->SetHeater(true);
    else if (desiredTemperature < currentTemperature) Temp->SetHeater(false);
    else
    {
      Temp->SetHeater(true);
      //delay(100);
      Temp->SetHeater(false);
      //delay(100);
    }
  }
}

Temperature::~Temperature()
{
}

void Temperature::setInterface(ITemperature* t)
{
  Temp = t;  
}
