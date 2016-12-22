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
  if(mProgram->GetProgramButton())
  {
    currentProgram++;
    if(currentProgram == 3)
    {
      currentProgram = 4;
    }
    mProgram->SetProgramIndicator(0);
    mProgram->SetProgramIndicator(currentProgram);
    Serial.print("current program: ");Serial.println(currentProgram);
    if(currentProgram >= 4)
    {
      currentProgram = 0;
    }
  }
}

char ProgramSelect::GetProgramType()
{
  return ('A');
}

void ProgramSelect::InstallStartHandler(void (* handler)())
{
  
}

void ProgramSelect::setProgramInterface(IProgram* p)
{
  mProgram = p;  
}

