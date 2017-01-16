#ifndef WATER_H
#define WATER_H

#include "IWater.h"

const int Full = 3;
const int Medium = 2;
const int Low = 1;
const int Empty = 0;

class Water
{
  private:
    IWater* iWater;
    int CurrentLevel;
    int DesiredLevel;

  public:
    Water(IWater *w);
    int CheckLevel();                    //will check if
    void SetLevel(int level);
    void Poll();                        //will check if
    void SetSink(boolean state);
    void SetDrain(boolean state);
    boolean CheckSink();
    boolean CheckDrain();
    
    ~Water();
};

#endif

