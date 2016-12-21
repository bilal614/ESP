#ifndef PROGRAMSELECT_H
#define PROGRAMSELECT_H

class ProgramSelect
{
public:
  ProgramSelect(IProgram *);
  void Poll();
  char GetProgramType();
  void InstallStartHandler(void (* handler)());
private:
  IProgram * mProgram;
  //current selected program
  char selectedProgram;
  void (* mStartHandler) (void);
};

#endif



