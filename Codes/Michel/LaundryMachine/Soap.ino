Soap::Soap()
{
  Soap::checkCpt1(); 
  Soap::checkCpt2();
}

Soap::Soap(ISoap * s)
{
  iSoap = s;
  Soap::checkCpt1(); 
  Soap::checkCpt2(); 
}
boolean Soap::checkCpt1()
{
  boolean soap1Status = iSoap->GetSoap1();
  if(soap1Status)
  {
    iSoap->SetSoap1(true);
  }
  else
  {
    iSoap->SetSoap1(true);
  }
  soapCpt1 = soap1Status;
  return soap1Status;
}

boolean Soap::checkCpt2()
{
  
  boolean soap2Status = iSoap->GetSoap2();
  if(soap2Status)
  {
    iSoap->SetSoap2(true);
  }
  else
  {
    iSoap->SetSoap2(true);
  }
  soapCpt2 = soap2Status;
  return soap2Status;
}

void Soap::lockCpt1(boolean set)
{
  soapCpt1 = set;
  if(set)
  {
    iSoap->SetSoap1(true);
  }
  else
  {
    iSoap->SetSoap1(false);
  }
}

void Soap::lockCpt2(boolean set)
{
  soapCpt2 = set;
  if(set)
  {
    iSoap->SetSoap2(true);
  }
  else
  {
    iSoap->SetSoap2(false);
  }
}

Soap::~Soap()
{
  //delete iSoap;  
}

void Soap::setInterface(ISoap* s)
{
    iSoap = s;   
}


