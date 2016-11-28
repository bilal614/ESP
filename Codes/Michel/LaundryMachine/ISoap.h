#ifndef ISOAP_H
#define ISOAP_H

class ISoap
{
public:
  // Inputs
  virtual boolean GetSoapCptStatus() = 0;
  // Outputs
  virtual void SetSoap2(int level) = 0;
  virtual boolean LockSoapCpt() = 0;
  virtual boolean UnlockSoapCpt() = 0;
};

#endif


