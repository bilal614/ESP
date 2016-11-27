#ifndef ISOAP_H
#define ISOAP_H

class ISoap
{
public:
  // Inputs
  virtual boolean GetSoapCptStatus();
  // Outputs
  virtual void SetSoap2(int level) = 0;
  virtual boolean LockSoapCpt();
  virtual boolean UnlockSoapCpt();
};

#endif


