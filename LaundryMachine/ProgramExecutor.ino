#include "ProgramExecutor.h"

ProgramExecutor::ProgramExecutor(IBuzzer * b, IMotor * m, ILock * l, ISoap * s, ITemperature * t, IWater * w)
{
  //mBuzzer.setInterface(b);
  mMotor.setInterface(m);
  mLock.setInterface(l);
  mSoap.setInterface(s);
  //mTemperature.setInterface(t);
  mWater.setInterface(w);
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
      //Prewash:
      mWater.SetLevel(2);
      mSoap.lockCpt1(false);
      mMotor.rotateLM( 1, 2);
      delay(6000);
      stopDelay(2);
      //mMotor.Stop();
      
      mMotor.rotateLM( 0, 2);
      delay(6000);
      stopDelay(2);
      //mMotor.Stop();
      mWater.SetLevel(0);
      
      //Main-wash (note: add temperature later)
      /*
       * if(mWater.CheckLevel()>0)
       * {
       *  mTemperature->SetTemperature(2);
       * }
       */
       //step 1)
      mWater.SetLevel(2);
      mSoap.lockCpt2(false);
      mMotor.rotateLM(1, 2);
      delay(6000);
      //mMotor.Stop();
      stopDelay(2);
      
      mMotor.rotateLM(0, 2);
      delay(6000);
      //mMotor.Stop();
      stopDelay(2);
      
      mMotor.rotateLM(1, 2);
      delay(6000);
      //mMotor.Stop();
      stopDelay(2);
      
      mMotor.rotateLM(0, 2);
      delay(6000);
      //mMotor.Stop();
      stopDelay(2);
      
      mWater.SetLevel(0);
      //step 2)
      /*
      mWater.SetLevel(2);
      mMotor.rotateLM(6000, 1, 2);
      mMotor.rotateLM(6000, 0, 2);
      mMotor.rotateLM(6000, 1, 2);
      mMotor.rotateLM(6000, 0, 2);
      mWater.SetLevel(0);
      //step 3)
      mMotor.Centrifugation();
      mWater.SetSink(true);
    */
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

void ProgramExecutor::stopDelay(int Speed)
{
  mMotor.Stop();
  if(Speed == 3)
  {
    delay(5000);
  }
  if(Speed == 2)
  {
    delay(2000);
  }
  if(Speed == 1)
  {
    delay(1000);
  }
}
