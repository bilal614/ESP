#ifndef PROGRAMEXECUTOR_H
#define PROGRAMEXECUTOR_H

#include "Buzzer.h"
#include "Lock.h"
#include "Motor.h"
//#include "Program.h"
#include "Soap.h"
#include "Temperature.h"
#include "Water.h"
//#include "CoinWallet.h"
#include "ProgramSettings.h"

const int DelayValue = 6000;

class ProgramExecutor
{
public:
  ProgramExecutor(IBuzzer* b, IMotor* m, ILock* l, ISoap* s, ITemperature* t, IWater* w);
  boolean Start(ProgramSettings *);
  boolean StepSwitches();
  boolean StepCoinWallet();
  boolean IsReady(char prog);
  void setCoinWallet(CoinWallet* c);
  void stopDelay(int Speed);
  void Centrifugate(char prog);
  void Prewash(char prog);
  void DoFullRotating(int NbrOfTimes, int Speed, int DelayVal);
  void Mainwash_Phase1(char prog);
  void Mainwash_Phase2(char prog);
  void tempDelay(int d);
private:
  Buzzer  mBuzzer;
  Motor  mMotor;
  Lock  mLock;
  Soap  mSoap;
  Temperature mTemperature;
  Water  mWater;
  CoinWallet * mCoinWallet;
  ProgramSettings* mProgramSettings;
};

#endif


