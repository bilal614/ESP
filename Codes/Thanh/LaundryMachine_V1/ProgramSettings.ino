const char A = 'A';
const char B = 'B';
const char C = 'C';

ProgramSettings::ProgramSettings()
{  
}

ProgramSettings::ProgramSettings(char type)
{
  switch (type)
  {
    case 'A':
      type = 'A';
      cost = 360;
      break;
    case 'B':
      type = 'B';
      cost = 480;
      break;
    case 'C':
      type = 'C';
      cost = 510;
      break;
    default:
      Serial.print("Incorrect program argument...");
      // TODO: provide error message
      break;
  }
}

String ProgramSettings::ToString()
{
  String one = String(type);
  String two = String(cost);
  String temp = String("Program type: " + one + ", Cost: " + two);
  return temp;
}

char ProgramSettings::GetProgramType()
{
  return type;
}
int ProgramSettings::GetProgramCost()
{
  return cost;
}

void ProgramSettings::setProgramAndCost(char prog)
{
  switch (prog)
  {
    case 'A':
      type = 'A';
      cost = 360;
      break;
    case 'B':
      type = 'B';
      cost = 480;
      break;
    case 'C':
      type = 'C';
      cost = 510;
      break;
    default:
      Serial.print("Incorrect program argument...");
      // TODO: provide error message
      break;
  }
}

