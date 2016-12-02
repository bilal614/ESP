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

void setup()
{
  Serial.begin(9600);
  mControl = new HardwareControl();
}

void loop()
{
  //Only for testing the HardwareControl class
  //  if (mControl->GetCoin10Button())
  //  {
  //    Serial.println("Button coin 10 is pressed");
  //    mControl->SetCoin10(1,0,0);
  //  }
  //  if (mControl->GetCoin50Button())
  //  {
  //    Serial.println("Button coin 50 is pressed");
  //    mControl->SetCoin50(1);
  //  }
  if (mControl->GetCoin50Button())
  {
    Serial.println("Button coin 50 is pressed");
    mControl->SetCoin50(2);
  }
  //
  //delete mControl;
}


