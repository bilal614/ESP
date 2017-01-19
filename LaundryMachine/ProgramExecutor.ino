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
      /*mWater.SetLevel(2);
        mSoap.lockCpt1(false);
        mMotor.rotateLM( 1, 2);
        delay(6000);
        stopDelay(2);
        //mMotor.Stop();

        mMotor.rotateLM( 0, 2);
        delay(6000);
        stopDelay(2);
        //mMotor.Stop();
        mWater.SetLevel(Empty);*/

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
      //step 3)
      Centrifugate('B');
      //mCoinWallet->Withdraw(360);

      //Unlock
    }
    if (ProgramType == 'C')
    {
      //execute program C recipe
      //Prewash:
      Prewash('C');
      //step 3)
      Centrifugate('C');
      //mCoinWallet->Withdraw(360);
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
    mMotor.rotateLM(1, 3);
    delay(3000);
    stopDelay(3);
    mMotor.rotateLM(0, 3);
    delay(3000);
    stopDelay(3);
    mWater.SetSink(false);
  }
  else if (prog == 'C')
  {
    mWater.SetSink(true);
    mMotor.rotateLM(1, 3);
    delay(3000);
    stopDelay(3);
    mMotor.rotateLM(0, 3);
    delay(3000);
    stopDelay(3);
    mMotor.rotateLM(1, 3);
    delay(3000);
    stopDelay(3);
    mMotor.rotateLM(0, 3);
    delay(3000);
    stopDelay(3);
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
    mWater.SetDrain(1);
    delay(8000);
    delay(10000);
    mWater.SetDrain(0);
    
    mSoap.lockCpt1(false);
    mMotor.rotateLM(1, 2);
    delay(6000);
    stopDelay(2);
    mMotor.rotateLM(0, 2);
    delay(8000);
    stopDelay(2);
    mWater.SetLevel(0);
  }
  else if (prog == 'B' || prog == 'C') // Heat needed at 50%
  {
    mWater.SetLevel(2);
    //Add the heating
    mSoap.lockCpt1(false);
    mMotor.rotateLM(1, 2);
    delay(3000);
    stopDelay(2);
    mMotor.rotateLM(0, 2);
    delay(3000);
    stopDelay(2);
    mWater.SetLevel(0);
  }
  else
  {
    Serial.println("You entered an innapropriate value for Prewash!");
  }
}
