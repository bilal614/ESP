#include <Wire.h>
#include <Centipede.h>

#include "IBuzzer.h"
#include "ICoin.h"
#include "ILock.h"
#include "IMotor.h"
#include "IProgram.h"
#include "ISoap.h"
#include "ITemperature.h"
#include "IWater.h"

#include "HardwareControl.h"
#include "CoinWallet.h"
#include "ProgramSelect.h"
#include "ProgramSettings.h"
#include "ProgramExecutor.h"

static HardwareControl * mControl;
static IBuzzer * mBuzzer;
static ICoin * mCoin;
static IMotor * mMotor;
static ILock * mLock;
static IProgram * mProgram;
static ISoap * mSoap;
static ITemperature * mTemperature;
static IWater * mWater;
static CoinWallet * mCoinWallet;
static ProgramSelect * mProgramSelect;
static ProgramSettings * mProgramSettings;
static ProgramExecutor * mProgramExecutor;

//only for testing at this moment

void setup()
{
  Serial.begin(9600);
  mControl = new HardwareControl();
  mCoinWallet = new CoinWallet(mControl);
  mProgramExecutor = new ProgramExecutor(mControl, mControl, mControl, mControl, mControl, mControl);
  mProgramExecutor->setCoinWallet(mCoinWallet);
  mProgramSelect = new ProgramSelect(mControl);
}
int count = 0;
void loop()
{
  //mProgramExecutor->Step();
  mProgramExecutor->StepCoinWallet(); 
  mProgramSelect->Poll();
  /*if (mControl->GetCoin10Button())
  {
    count++;
  }
  if (count == 1)
  {
    //Serial.println("First press");
    mControl->SetCoin10(0x01);
  }
  else if (count == 2)
  {
    //Serial.println("Second press");
    mControl->SetCoin10(0x02);
  }
  else if (count == 3)
  {
    //Serial.println("Third press");
    mControl->SetCoin10(0x04);
  }
  else
  {
    count = 0;
  }*/
}


