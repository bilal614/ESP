#include "ProgramExecutor.h"

ProgramExecutor::ProgramExecutor(IBuzzer * b, IMotor * m, ILock * l, ISoap * s, ITemperature * t, IWater * w)
{
  //mBuzzer.setInterface(b);
  //mMotor.setInterface(m);
  mLock.setInterface(l);
  mSoap.setInterface(s);
  //mTemperature.setInterface(t);
  //mWater.setInterface(w);
}

boolean ProgramExecutor::Start(ProgramSettings * p)
{
  mProgramSettings = p;
  char ProgramType = mProgramSettings->GetProgramType();
  int ProgramCost = mProgramSettings->GetProgramCost();
  int moneyInWallet = mCoinWallet->GetAmount();
  if(moneyInWallet >= ProgramCost && StepSwitches())
  {
    if(ProgramType == 'A')
    {
      //execute program A recipe
    }
    if(ProgramType == 'B')
    {
      //execute program B recipe
      
    }
    if(ProgramType == 'C')
    {
      //execute program A recipe
      
    }
    Serial.print("Selected program: ");Serial.println(ProgramType);
    Serial.println("There is enough money for this wash.");  
  }
  return (true);
}

boolean ProgramExecutor::StepSwitches()//this function checks if the switches for the soap and door are locked or not and returns true if yes, else false
{
  boolean doorLock = mLock.lockMachine();
  //delay(1000);
  boolean soap1Lock = mSoap.checkCpt1();
  //delay(1000);
  boolean soap2Lock = mSoap.checkCpt2();
  if(doorLock && soap1Lock && soap2Lock)
  {
    return (true);
  }
  else
  {
    return false;
  }
}

boolean ProgramExecutor::IsReady(char prog)
{
  mProgramSettings->setProgramAndCost(prog);
  
  int walletMoney = mCoinWallet->GetAmount();

  int progCost = mProgramSettings->GetProgramCost();
  
  if(walletMoney >= progCost)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void ProgramExecutor::setCoinWallet(CoinWallet* c)
{
  mCoinWallet = c;  
}

boolean ProgramExecutor::StepCoinWallet()
{
  mCoinWallet->Poll();
}
