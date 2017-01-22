#ifndef ICOIN_H
#define ICOIN_H

class ICoin
{
  public:
    // Inputs
    virtual boolean GetCoin10Button() = 0;
    virtual boolean GetCoin50Button() = 0;
    virtual boolean GetCoin200Button() = 0;
    virtual boolean GetClearButton() = 0;
    // Outputs
    //leds is the nr of led need to be turn on
    //limited of the hardware, so need to check for the range of leds
    //could be make sounds when the capacity is full
    //leds is indicator which LED will be turn on
    // eg. Call SetCoin10(B00000111) means 3 coins 10 is added
    virtual void SetCoin10(unsigned char led) = 0;
    virtual void SetCoin50(unsigned char led) = 0;
    virtual void SetCoin200(unsigned char led) = 0;


};

#endif


