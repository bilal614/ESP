Water::Water(IWater * w)
{
  iWater = w;
}

int Water::CheckLevel()
{}

void Water::SetLevel(int level)
{}

void Water::Poll()
{}

void Water::SetSink(boolean state)
{}

void Water::SetDrain(boolean state)
{}

boolean Water::CheckSink()
{}

boolean Water::CheckDrain()
{

}

Water::~Water()
{
  //delete iWater;  
}

