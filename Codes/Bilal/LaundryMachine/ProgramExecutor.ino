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
  if(moneyInWallet >= ProgramCost)
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

boolean ProgramExecutor::StepSwitches()
{
  mLock.lockMachine();
  //delay(1000);
  mSoap.checkCpt1();
  //delay(1000);
  mSoap.checkCpt2();
  //delay(1000);
  //mCoinWallet->Poll();
  //mTemperature.Poll();
  return (true);
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
