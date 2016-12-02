#ifndef IPROGRAM_H
#define IPROGRAM_H

class IProgram
{
public:
  // Inputs
  /*Does the start button is pressed or not*/
  virtual boolean GetStartButton() = 0;
  virtual boolean GetProgramButton() = 0;
  // Outputs
  /*Based on the programIndicator parrametter, the coresponding LED will be turn on*/
  virtual void SetProgramIndicator(int programIndicator) = 0;
  virtual void SetGroup(int group) = 0;//arguments can be 0,1 and  2
  virtual void SetData(int data) = 0;//arguments can be the combination of last 3 bits
};

#endif


