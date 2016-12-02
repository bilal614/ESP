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
    void SetCoin10(byte firstCoin, byte secondCoin, byte thirdCoin);
    void SetCoin50(int leds);
    void SetCoin200(int leds);
    void ClearCoin10(int leds);
    void ClearCoin50(int leds);
    void ClearCoin200(int leds);

    /* ITemperature */
    //inputs
    int GetTemperature();
    //outputs
    void IncreaseTemperature();
    void DecreaseTemperature();

    /* ILock */
    //inputs
    boolean GetLockStatus();

    /* IBuzzer */
    //inputs 
    boolean buzzerOn();
    //outputs
    void SetBuzzer();
    
    /* IMotor */
    void SetSpeed(char mode);
    void SetAndTrackTime();
    void SetDirection(int dir);
    void CheckLoadingLevel(int level);
    void StartMotor();
    void StopMotor();
        
    /* IProgram */
    boolean GetStartButton();
    void SetProgramIndicator(int program);
    
    /* IWater */
    void SetWaterLevel(int level);
    bool CheckWaterLevel();
    void SinkWater();
    void SetDrain(int level);
        
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



