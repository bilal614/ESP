#ifndef ICOIN_H
#define ICOIN_H

class ICoin
{
public:
  // Inputs
  virtual boolean GetCoin10Button() = 0;
  virtual boolean GetCoin50Button() = 0;
  virtual boolean GetCoin200Button() = 0;
  // Outputs
  //leds is the nr of led need to be turn on 
  //limited of the hardware, so need to check for the range of leds
  //could be make sounds when the capacity is full
  virtual void SetCoin10(byte firstCoin, byte secondCoin, byte thirdCoin) = 0;
  virtual void SetCoin50(int leds) = 0;
  virtual void SetCoin200(int leds) = 0;

  virtual void ClearCoin10(int leds) = 0;
  virtual void ClearCoin50(int leds) = 0;
  virtual void ClearCoin200(int leds) = 0;
  virtual boolean GetClearButton() = 0;
};

#endif


