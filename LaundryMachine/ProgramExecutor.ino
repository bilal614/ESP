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
  if (moneyInWallet >= ProgramCost && StepSwitches())
  {
    if (ProgramType == 'A')
    {
      //execute program A recipe
      //Prewash:
      Prewash('A');

      //Main-wash (note: add temperature later)
      /*
         if(mWater.CheckLevel()>0)
         {
          mTemperature->SetTemperature(2);
         }
      */
      //step 1)
      /*mWater.SetLevel(2);
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

        mWater.SetLevel(0);*/
      //step 2)
      /*
        mWater.SetLevel(2);
        mMotor.rotateLM(6000, 1, 2);
        mMotor.rotateLM(6000, 0, 2);
        mMotor.rotateLM(6000, 1, 2);
        mMotor.rotateLM(6000, 0, 2);
        mWater.SetLevel(0);
        //step 3)
        Centrifugate('A');
      */
      //mCoinWallet->Withdraw(360);

      //Unlock
    }
    if (ProgramType == 'B')
    {
      //execute program B recipe
      //Prewash:
      Prewash('B');

      //Main-wash (note: add temperature later)
      /*
         if(mWater.CheckLevel()>0)
         {
          mTemperature->SetTemperature(2);
         }
      */
      //step 1)


      //step 3)
      Centrifugate('B');
      //mCoinWallet->Withdraw(480);

      //Unlock
    }
    if (ProgramType == 'C')
    {
      //execute program C recipe
      //Prewash:
      Prewash('C');

      //Main-wash (note: add temperature later)
      /*
         if(mWater.CheckLevel()>0)
         {
          mTemperature->SetTemperature(2);
         }
      */
      //step 1)

      //step 3)
      Centrifugate('C');
      //mCoinWallet->Withdraw(510);
      //Unlock

    }
    Serial.print("Selected program: "); Serial.println(ProgramType);
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
  if (doorLock && soap1Lock && soap2Lock)
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

  if (walletMoney >= progCost)
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
  if (Speed == 3)
  {
    delay(5000);
  }
  if (Speed == 2)
  {
    delay(2000);
  }
  if (Speed == 1)
  {
    delay(1000);
  }
}

void ProgramExecutor::Centrifugate(char prog)
{
  if (prog == 'A' || prog == 'B')
  {
    mWater.SetSink(true);
    DoFullRotating(1, 3, (DelayValue/2));
    mWater.SetSink(false);
  }
  else if (prog == 'C')
  {
    mWater.SetSink(true);
    DoFullRotating(2, 3, (DelayValue/2));
    mWater.SetSink(false);
  }
  else
  {
    Serial.println("You entered an innapropriate value for Program!");
  }
}

void ProgramExecutor::Prewash(char prog)
{
  if (prog == 'A') // No heat needed
  {
    mWater.SetLevel(2);
    mSoap.lockCpt1(false);
    DoFullRotating(1, 2, DelayValue);
    mWater.SetLevel(0);
  }
  else if (prog == 'B' || prog == 'C') // Heat needed at 50%
  {
    mWater.SetLevel(2);
    //Add the heating
    mSoap.lockCpt1(false);
    DoFullRotating(1, 2, DelayValue);
    mWater.SetLevel(0);
  }
  else
  {
    Serial.println("You entered an innapropriate value for Prewash!");
  }
}

void ProgramExecutor::Mainwash_Phase1(char prog)
{
  if (prog == 'A' || prog == 'B') // Same step 1 of main wash
  {
    mWater.SetLevel(2);
    //Add the heating 50%
    mSoap.lockCpt2(false);
    DoFullRotating(2, 2, DelayValue);
    mWater.SetLevel(0);
  }
  else if ( prog == 'C')
  {
    mWater.SetLevel(3);
    //Add the heating 100%
    mSoap.lockCpt2(false);
    DoFullRotating(4, 2, DelayValue);
    mWater.SetLevel(0);
  }
  else
  {
    Serial.println("You entered an innapropriate value for Main wash phase 1!");
  }
}

void ProgramExecutor::Mainwash_Phase2(char prog)  // No heat needed
{
  if (prog == 'A' || prog == 'B')  // Same step 2 of main wash 
  {
    mWater.SetLevel(2);
    DoFullRotating(2, 2, DelayValue);
    mWater.SetLevel(0);
  }
  else if (prog == 'B' || prog == 'C') // Same step 2 of main wash 
  {
    mWater.SetLevel(2);
    DoFullRotating(4, 2, DelayValue);
    mWater.SetLevel(0);
  }
  else
  {
    Serial.println("You entered an innapropriate value for Main wash phase 2!");
  }
}

void  ProgramExecutor::DoFullRotating(int NbrOfTimes, int Speed, int DelayVal) // Repeat complete rotating at a given speed
{
  int val = 0;
  while (val < NbrOfTimes)
  {
    mMotor.rotateLM(1, Speed);
    delay(DelayVal);
    stopDelay(Speed);
    mMotor.rotateLM(0, Speed);
    delay(DelayVal);
    stopDelay(Speed);
    val++;
  }
}
