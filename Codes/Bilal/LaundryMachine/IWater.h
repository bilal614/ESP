#ifndef IWATER_H
#define IWATER_H

#include "IWater.h"

class IWater
{
public:
  // Inputs
  virtual boolean GetWater1() = 0;
  virtual boolean GetWater2() = 0;
  
  // Outputs
  virtual void OpenSink() = 0;
  virtual void CloseSink() = 0;
  virtual void OpenDrain() = 0;
  virtual void CloseDrain() = 0;
  
};

#endif


