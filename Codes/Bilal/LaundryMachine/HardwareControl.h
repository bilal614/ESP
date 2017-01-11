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

    /* IProgram */
    boolean GetStartButton();
    void SetProgramIndicator(int program);
    boolean GetProgramButton();

    /* ISoap */
    //inputs
    boolean GetSoap1();
    boolean GetSoap2();
    //output
    void SetSoap1(boolean On);
    void SetSoap2(boolean On);

    /* ILock */
    //inputs
    boolean GetLockStatus();
    void SetLockStatus(boolean lock);

    /* IMotor */
    // Inputs
    // Outputs
    virtual void TurnLeft();
    virtual void TurnRight();
    virtual void StartSpeed1();
    virtual void StartSpeed2();
    virtual void StopSpeed1();
    virtual void StopSpeed2();

     /* IWater */
    // Inputs
    virtual boolean GetWater1();
    virtual boolean GetWater2();
    // Outputs
    virtual void OpenSink();
    virtual void CloseSink();
    virtual void OpenDrain();
    virtual void CloseDrain();
    
    /* ITemperature */
    //inputs
    int GetTemperature();
    //outputs
    void SetHeater(bool sw1tch);

    /* IBuzzer */
    //inputs
    //outputs
    void SetBuzzer(int ms);

    

   



  private:
    Centipede centipede;
    void SetKeySelect(int value);
    void SetGroup(int group);
    void SetData(int data);
    void Strobe();
};

#endif



