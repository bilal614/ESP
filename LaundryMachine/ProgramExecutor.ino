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
  return (true);
}

boolean ProgramExecutor::Step()
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

boolean ProgramExecutor::IsReady()
{
  return (false);
}

void ProgramExecutor::setCoinWallet(CoinWallet* c)
{
  mCoinWallet = c;  
}

boolean ProgramExecutor::StepCoinWallet()
{
  mCoinWallet->Poll();
}
