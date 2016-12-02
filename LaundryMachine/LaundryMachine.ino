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
  //    mControl->SetCoin10(B00000101);
  //    mControl->SetCoin50(B00000111);
  //  }
  //  if (mControl->GetClearButton())
  //  {
  //    mControl->SetCoin10(0x00);
  //    mControl->SetCoin50(0x00);
  //  }
  if (mControl->GetProgramButton())
  {
    Serial.println("Program button is pressed");
    mControl->SetProgramIndicator(B00000100);
  }
  //  if (mControl->GetStartButton())
  //  {
  //    Serial.println("Start button is pressed");
  //  }
  //delete mControl;
}


