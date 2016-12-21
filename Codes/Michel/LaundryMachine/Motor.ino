Motor::Motor(IMotor * m)
{
  iMotor = m;
}

void Motor::Start(int s)
{}

void Motor::Stop()
{}

int Motor::GetSpeed()
{
  }
  
boolean Motor::GetDirection()
{}
  
void Motor::SetDirection(boolean dir)
{}    

Motor::~Motor()
{
  //delete iMotor;  
}

