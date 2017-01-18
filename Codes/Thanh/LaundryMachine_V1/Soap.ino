Soap::Soap()
{
}

Soap::Soap(ISoap * s)
{
  iSoap = s;
}
boolean Soap::checkCpt1()
{
  boolean soap1Status = iSoap->GetSoap1();
  if(soap1Status)
  {
    iSoap->SetSoap1(true);
    //Serial.println("soap cpt 1 is locked");
  }
  else
  {
    iSoap->SetSoap1(false);
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
    //Serial.println("soap cpt 2 is locked");
  }
  else
  {
    iSoap->SetSoap2(false);
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


