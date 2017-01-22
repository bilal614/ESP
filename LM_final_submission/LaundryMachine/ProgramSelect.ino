#include "ProgramSelect.h"


ProgramSelect::ProgramSelect()
{
  currentProgram = 1;
}

ProgramSelect::ProgramSelect(IProgram * p)
{
  mProgram = p;
  currentProgram = 1;
}

void ProgramSelect::Poll()
{
  char progamType = GetProgramType();
  //Serial.print("current program: ");
  //Serial.println(progamType);
  //Need to be called there instead of GetProgramType to make sure that the increasing of currentProgram only done when the
  //Program Button is pressed, previously it turned out an error when it was called in GetProgramType;
  if (mProgram->GetProgramButton())
  {
    currentProgram ++;
    if (currentProgram >= 4)
    {
      currentProgram = 1;
    }
  }
  if (currentProgram >= 4)
  {
    currentProgram = 0;
  }
  if (mProgram->GetStartButton())
  {
    //Serial.println("Start is pressed");
    //    if (mStartHandler != NULL)
    //    {
    //      mStartHandler();
    //    }
  }
}

char ProgramSelect::GetProgramType()
{
  //Serial.print("current program: ");Serial.println(currentProgram);
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
  mStartHandler = handler;
}

void ProgramSelect::setProgramInterface(IProgram* p)
{
  mProgram = p;
}

boolean ProgramSelect::StartIsPressed()
{
  return mProgram->GetStartButton();
}

ProgramSelect::~ProgramSelect()
{}

