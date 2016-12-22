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
    /* ICoin */
    //inputs
    boolean GetCoin10Button();
    boolean GetCoin50Button();
    boolean GetCoin200Button();
    boolean GetClearButton();
    //outputs
    void SetCoin10(byte led);
    void SetCoin50(byte led);
    void SetCoin200(byte led);

    /* ITemperature */
    //inputs
    int GetTemperature();
    //outputs
    void SetHeater(bool sw1tch);

    /* ILock */
    //inputs
    boolean GetLockStatus();
    void SetLockStatus(boolean lock);

    /* IBuzzer */
    //inputs
    //outputs
    void SetBuzzer(int ms);

    /* IMotor */
    void SetSpeed(int level);
    void SetDirection(char dir);
    void CheckLoadingLevel(int level);
    void StartMotor();
    void StopMotor();

    /* IProgram */
    boolean GetStartButton();
    void SetProgramIndicator(int program);
    boolean GetProgramButton();

    /* IWater */
    void SetWaterLevel(int level);
    bool CheckWaterLevel(int level);
    void SinkWater();

    /* ISoap */
    //inputs
    boolean GetSoap1();
    boolean GetSoap2();
    //output
    void SetSoap1(boolean On);
    void SetSoap2(boolean On);

  private:
    Centipede centipede;
    void SetKeySelect(int value);
    void SetGroup(int group);
    void SetData(int data);
    void Strobe();
};

#endif



