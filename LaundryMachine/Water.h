#ifndef WATER_H
#define WATER_H

#include "IWater.h"

const int Full = 3;
const int Medium_water = 2;
const int Low_water = 1;
const int Empty = 0;

class Water
{
  private:
    IWater* oWater;
	int DesiredLevel;
	int CurrentLevel;
    
  public:
    Water();
    Water(IWater *);
    int CheckLevel();
    void SetLevel(int level);
    void SetSink(boolean state);
    void SetDrain(boolean state);
    ~Water();
    void setInterface(IWater* w);
};

#endif

