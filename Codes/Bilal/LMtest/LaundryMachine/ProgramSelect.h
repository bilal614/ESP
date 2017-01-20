#ifndef PROGRAMSELECT_H
#define PROGRAMSELECT_H

#include "IProgram.h"

class ProgramSelect
{
public:
  ProgramSelect();
  ProgramSelect(IProgram *);
  ~ProgramSelect();
  void Poll();
  char GetProgramType();
  void InstallStartHandler(void (* handler)());
  void setProgramInterface(IProgram* p);
  boolean StartIsPressed();
private:
  IProgram * mProgram;
  void (* mStartHandler) (void);
  int currentProgram;
};

#endif



