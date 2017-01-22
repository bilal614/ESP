#ifndef PROGRAMSETTINGS_H
#define PROGRAMSETTINGS_H

class ProgramSettings
{
  public:
    ProgramSettings();
    ProgramSettings(char);
    String ToString();
    char GetProgramType();
    int GetProgramCost();
    void setProgramAndCost(char prog);
  private:
    char type; /* 'A', 'B' or 'C' */
    int cost;
    // etc.
};

#endif

