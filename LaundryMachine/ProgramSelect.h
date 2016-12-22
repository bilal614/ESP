#ifndef PROGRAMSELECT_H
#define PROGRAMSELECT_H

class ProgramSelect
{
public:
  ProgramSelect();
  ProgramSelect(IProgram *);
  void Poll();
  char GetProgramType();
  void InstallStartHandler(void (* handler)());
  void setProgramInterface(IProgram* p);
private:
  IProgram * mProgram;
  void (* mStartHandler) (void);
  int currentProgram;
};

#endif



