#ifndef IBUZZER_H
#define IBUZZER_H

class IBuzzer
{
public:
  //input
  virtual void SetBuzzer() = 0;
  
  //output  
  virtual boolean buzzerOn() = 0;
};

#endif


