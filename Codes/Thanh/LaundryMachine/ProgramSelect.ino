#include "ProgramSelect.h"


ProgramSelect::ProgramSelect()
{
  currentProgram = 0;
}

ProgramSelect::ProgramSelect(IProgram * p)
{
  mProgram = p;
  currentProgram = 0;
}

void ProgramSelect::Poll()
{
  char progamType = GetProgramType();
  Serial.print("current program: ");
  Serial.println(progamType);
  if (currentProgram >= 4)
  {
    currentProgram = 0;
  }
}

char ProgramSelect::GetProgramType()
{
  if (mProgram->GetProgramButton())
  {
    currentProgram ++;
  }
  if (currentProgram == 1)
  {
    mProgram->SetProgramIndicator(0x01);
    return ('A');

  }
  if (currentProgram == 2)
  {
    mProgram->SetProgramIndicator(0x01 << 1);
    return ('B');  
  }
  if (currentProgram == 3)
  {
    mProgram->SetProgramIndicator(0x01 << 2);
    return ('C');
  }
}

void ProgramSelect::InstallStartHandler(void (* handler)())
{
  
}

void ProgramSelect::setProgramInterface(IProgram* p)
{
  mProgram = p;
}

