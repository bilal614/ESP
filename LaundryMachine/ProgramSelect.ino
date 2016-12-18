#include "ProgramSelect.h"

ProgramSelect::ProgramSelect(IProgram * p)
{
  mProgram = p;
}

void ProgramSelect::Poll()
{
  
}

char ProgramSelect::GetProgramType()
{
  return ('A');
}

void ProgramSelect::InstallStartHandler(void (* handler)())
{
  
}

