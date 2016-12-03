#ifndef HARDWARECONTROL_H
#define HARDWARECONTROL_H

#include "Centipede.h"

#include "IBuzzer.h"
#include "ICoin.h"
#include "ILock.h"
#include "IMotor.h"
#include "IProgram.h"
#include "ISoap.h"
#include "ITemperature.h"
#include "IWater.h"

class HardwareControl: public IBuzzer, public ICoin, public ILock, public IMotor, public IProgram, public ISoap, public ITemperature, public IWater
{
  public:
    HardwareControl();
    // Inputs
    boolean GetCoin10Button();
    boolean GetCoin50Button();
    boolean GetCoin200Button();
    boolean GetClearButton();
    boolean GetStartButton();
    boolean GetLockStatus();
    boolean GetSoapCptStatus();
    // Outputs
    void SetBuzzer(int ms);
    void SetSoap2(int level);
    void SetDrain(int level);
    void SetDirection(int dir);
    void SetProgramIndicator(int program);
    void SetCoin50(int leds);
    void SetCoin10(int leds);
    void SetCoin200(int leds);
    boolean LockDoor(boolean &lockStatus);
    boolean UnlockDoor(boolean &lockStatus);
    boolean LockSoapCpt();
    boolean UnlockSoapCpt();
    void ClearCoin10(int leds);
    void ClearCoin50(int leds);
    void ClearCoin200(int leds);
    void SetSpeed(char mode);
    void SetAndTrackTime();
    void CheckLoadingLevel(int level);
    void StartMotor();
    void StopMotor();
    int GetTemperature();
    void SetTemperature(int level);
    void SetWaterLevel(int level);
    bool CheckWaterLevel();
    void SinkWater();
  private:
    Centipede centipede;
    void SetKeySelect(int value);
    void SetGroup(int group);
    void SetData(int data);
    void Strobe();
};

#endif



