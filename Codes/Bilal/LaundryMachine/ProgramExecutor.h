#ifndef PROGRAMEXECUTOR_H
#define PROGRAMEXECUTOR_H

//#include "Buzzer.h"
#include "Lock.h"
//#include "Motor.h"
//#include "Program.h"
#include "Soap.h"
//#include "Temperature.h"
//#include "Water.h"
//#include "CoinWallet.h"
#include "ProgramSettings.h"

class ProgramExecutor
{
public:
  //ProgramExecutor(Buzzer , Motor , Lock , Soap , Temperature , Water , CoinWallet );
  boolean Start(ProgramSettings *);
  boolean Step();
  boolean IsReady();
private:
  //Buzzer  mBuzzer;
  //Motor  mMotor;
  Lock  mLock;
  Soap  mSoap;
  //Temperature * mTemperature;
  //Water  mWater;
  //CoinWallet  mCoinWallet;
  ProgramSettings* mProgramSettings;
};

#endif


