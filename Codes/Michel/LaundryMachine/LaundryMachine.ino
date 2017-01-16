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
#include "Motor.h"
#include "Water.h"

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
static Motor * myMotor;
static Water * myWater;

//only for testing at this moment
Centipede CS;

void setup()
{
  Serial.begin(9600);
  mControl = new HardwareControl();
  myMotor = new Motor(mControl);
  myWater = new Water(mControl);
  /*CS.initialize();
    for (int i = 0; i <= 15; i++)
    {
    CS.pinMode(i, OUTPUT);
    }
    CS.digitalWrite(OUT_SINK, LOW);
    CS.digitalWrite(OUT_DRAIN, LOW);*/

}
int count = 0;
void loop()
{

  /**** TESTING THE MOTOR FUNCTIONS *****/
  /*
     Testing to start the motor at different speed with the Laundry Machine device.
  */
  //myMotor->Start(1);
  /*
      Conclusion: It works properly!
  */

  /*
       Testing to stop the motor of the Laundry Machine device.
  */
  //delay(2000);
  //myMotor->Stop();
  //delay(1000);
  /*
      Conclusion: It works properly!
  */

  /*
       Testing to set the direction of the motor with the Laundry Machine device.
  */
  //delay(1000);
  //myMotor->SetDirection(1);
  //delay(2000);
  /*
      Conclusion: It works properly!
  */

  /***** END FOR MOTOR TESTING *****/


  /***** TESTING THE WATER FUNCTIONS *****/

  /*
       Testing to sink water of the Laundry Machine device.
  */
  //myWater->SetSink(1);
  /*
      Conclusion: It works properly!
  */

  /*
        Testing to drain water in the Laundry Machine device.
  */
  //myWater->SetDrain(1);
  /*
      Conclusion: It works properly!
  */

  /*
       Testing to start the motor at different speed with the Laundry Machine device.
  */
  myWater->SetLevel(Empty);               // Works properly
  //myWater->SetLevel(Low_water);           // Works properly
  //myWater->SetLevel(Medium_water);        // Works properly
  //myWater->SetLevel(Full);                // Works properly
  /*
      Conclusion: Seems It does not works properly!
  */

  /*
       Testing that we read the correct water level with the Laundry Machine device.
  */
  
  int val = myWater->CheckLevel();
  Serial.println("The water level is: "); Serial.println(val);
  delay(1000);
  /*
      Conclusion: It works properly!
  */

  /***** END FOR WATER TESTING *****/

}


