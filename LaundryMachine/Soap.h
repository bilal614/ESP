#ifndef SOAP_H
#define SOAP_H

#include "ISoap.h"

class Soap
{
  private:
    ISoap* iSoap;
    boolean soapCpt1;
    boolean soapCpt2;
    
  public:
    Soap(ISoap *s);
    boolean checkCpt1();//will check if soap switch 1 is turned on and will turn on soap 1 LED accordingly
    boolean checkCpt2();//will check if soap switch 2 is turned on and will turn on soap 2 LED accordingly
    void lockCpt1(boolean set);
    void lockCpt2(boolean set);
    ~Soap();
};

#endif

