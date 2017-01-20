#ifndef PROGRAMEXECUTOR_H
#define PROGRAMEXECUTOR_H

#include "IBuzzer.h"
#include "ILock.h"
#include "IMotor.h"
#include "IProgram.h"
#include "ISoap.h"
#include "ITemperature.h"
#include "IWater.h"
#include "CoinWallet.h"
#include "ProgramSettings.h"

class ProgramExecutor
{
public:
  ProgramExecutor(IBuzzer* b, IMotor* m, ILock* l, ISoap* s, ITemperature* t, IWater* w);
  boolean Start(ProgramSettings *);
  boolean StepSwitches();
  boolean StepCoinWallet();
  boolean IsReady(char prog);
  void setCoinWallet(CoinWallet* c);
private:
  Buzzer  mBuzzer;
  //Motor  mMotor;
  Lock  mLock;
  Soap  mSoap;
  Temperature mTemperature;
  //Water  mWater;
  CoinWallet * mCoinWallet;
  ProgramSettings* mProgramSettings;
};

#endif


