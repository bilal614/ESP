#include "Water.h"

Water::Water(IWater * w)
{
  iWater = w;
}

int Water::CheckLevel()
{
  return 0;
}

void Water::SetLevel(int level)
{}

void Water::Poll()
{}

void Water::SetSink(boolean state)
{}

void Water::SetDrain(boolean state)
{}

boolean Water::CheckSink()
{
  return false;
}

boolean Water::CheckDrain()
{
  return false;
}

Water::~Water()
{
  //delete iWater;  
}

