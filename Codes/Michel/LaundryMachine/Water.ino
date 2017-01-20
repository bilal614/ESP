
#include "Water.h"

Water::Water(IWater * w)
{
  oWater = w;
}

int Water::CheckLevel()
{
  if (!oWater->GetWater1() && !oWater->GetWater2())
  {
    return Empty;
  }
  else if (oWater->GetWater1() && !oWater->GetWater2())
  {
    return Low_water;
  }
  else if (!oWater->GetWater1() && oWater->GetWater2())
  {
    return Medium_water;
  }
  else
    return Full;
}

void Water::SetLevel(int level)
{
  int val;
  boolean state = true;

  if (level == Empty)                     //Empty state
  {
    while(state)
    {
    val = Water::CheckLevel();

    if (val == Empty)
    {
      //Stay at fixed level
      Water::SetSink(0);               //1 for ON and 0 for OFF
      Water::SetDrain(0);
      state = false;
    }
    else
    {
      Water::SetSink(1);                  //1 for ON and 0 for OFF
      Water::SetDrain(0);
    }
    }

  }
  else if (level == Low_water)                     //Filled at 33%
  {
    while(state)
    {
    val = Water::CheckLevel();

    if (val == Low_water)
    {
      //Stay at fixed level
      Water::SetSink(0);
      Water::SetDrain(0);
      state = false;
    }
    else if (val > Low_water)
    {
      Water::SetSink(1);                  //1 for ON and 0 for OFF
      Water::SetDrain(0);
    }
    else
    {
      Water::SetSink(0);                  //1 for ON and 0 for OFF
      Water::SetDrain(1);
    }
    }

  }
  else if (level == Medium_water)             //Filled at 66%
  {
    while(state)
    {
    val = Water::CheckLevel();

    if (val == Medium_water)
    {
      //Stay at fixed level
      Water::SetSink(0);
      Water::SetDrain(0);
      state = false;
    }
    else if (val > Medium_water)
    {
      Water::SetSink(1);                  //1 for ON and 0 for OFF
      Water::SetDrain(0);
    }
    else
    {
      Water::SetSink(0);                  //1 for ON and 0 for OFF
      Water::SetDrain(1);
    }
    }
  }
  else if (level == Full)                  //Filled at 100%
  {
     while(state)
    {
    val = Water::CheckLevel();

    if (val == Full)
    {
      //Stay at fixed level
      Water::SetSink(0);
      Water::SetDrain(0);
      state = false;
    }
    else if (val > Full)
    {
      //Print error message
      Serial.println("The value must be between less or egual to 3!");
      Water::SetSink(0);                  //1 for ON and 0 for OFF
      Water::SetDrain(0);
    }
    else
    {
      Water::SetSink(0);                  //1 for ON and 0 for OFF
      Water::SetDrain(1);
    }
    }
  }

}

void Water::SetSink(boolean state) //1 for ON and 0 for OFF
{
  if (state)
  {
    oWater->OpenSink();
  }
  else
  {
    oWater->CloseSink(); ;
  }
}

void Water::SetDrain(boolean state) //1 for ON and 0 for OFF
{
  if (state)
  {
    oWater->OpenDrain();
  }
  else
  {
    oWater->CloseDrain();
  }
}

Water::~Water()
{
  //delete oWater;
}

