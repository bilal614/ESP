
#include "Water.h"

Water::Water(IWater * w)
{
  iWater = w;
}

int Water::CheckLevel()
{
  if (!iWater->GetWater1() && !iWater->GetWater2())
  {
    return Full;
  }
  else if (iWater->GetWater1() && !iWater->GetWater2())
  {
    return Medium;
  }
  else if (!iWater->GetWater1() && iWater->GetWater2())
  {
    return Low_water;
  }
  else
    return Empty;
}

void Water::SetLevel(int level)
{
  if (level == Empty)                     //Empty state
  {
    Water::SetSink(1);                  //1 for ON and 0 for OFF
    Water::SetDrain(0);

    if (Water::CheckLevel() == Empty)
    {
      //Stay at fixed level
      Water::SetSink(1);
      Water::SetDrain(1);
    }
  }
  else if (level == Low_water)                     //Filled at 33%
  {
    Water::SetSink(0);                  //1 for ON and 0 for OFF
    Water::SetDrain(1);

    if (Water::CheckLevel() == Low_water)
    {
      //Stay at fixed level
      Water::SetSink(1);
      Water::SetDrain(1);
    }
  }
  else if (level == Medium)             //Filled at 66%
  {
    Water::SetSink(0);                  //1 for ON and 0 for OFF
    Water::SetDrain(1);

    if (Water::CheckLevel() == Medium)
    {
      //Stay at fixed level
      Water::SetSink(1);                  //1 for ON and 0 for OFF
      Water::SetDrain(1);
    }
  }
  else if (level == Full)                  //Filled at 100%
  {

    Water::SetSink(0);                  //1 for ON and 0 for OFF
    Water::SetDrain(1);

    if (Water::CheckLevel() == Full)
    {
      //Stay at fixed level
      Water::SetSink(1);
      Water::SetDrain(1);
    }
  }
  else                                 // Fixed Level
  {
    Water::SetSink(1);                  //1 for ON and 0 for OFF
    Water::SetDrain(1);
  }
}

void Water::SetSink(boolean state)
{
  if (state)
  {
    iWater->OpenSink();
  }
  else
  {
    iWater->CloseSink(); ;
  }
}

void Water::SetDrain(boolean state)
{
  if (state)
  {
    iWater->OpenDrain();
  }
  else
  {
    iWater->CloseDrain();
  }
}


Water::~Water()
{
  //delete iWater;
}

