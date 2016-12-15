#include "CoinWallet.h"

CoinWallet::CoinWallet(ICoin * c)
{
  mCoin = c;
  nrOfCoin10 = 0;
  nrOfCoin50 = 0;
  nrOfCoin200 = 0;
}

void CoinWallet::Poll()
{
  AddCoin10();
  //AddCoin50();
  //AddCoin200();
  //WithdrawAll();
}

int CoinWallet::GetAmount()
{
  return balance;
}

boolean CoinWallet::Withdraw(int amount)
{
  if (amount > balance)
  {
    return false;
  }
  else
  {
    balance -= amount;
    return ;
  }
}

void CoinWallet:: AddCoin10()
{
  /*if (mCoin->GetCoin10Button() && nrOfCoin10 < 3)
    {
    nrOfCoin10++;
    mCoin->SetCoin10(mappingCoin( nrOfCoin10++));
    Serial.println("I am having");
    Serial.println(nrOfCoin10, BIN);
    }*/
  if (mCoin->GetCoin10Button() && nrOfCoin10 < 3)
  {
    Serial.println("Button of coin 10 is pressed");
    nrOfCoin10 = 1;
    Serial.println("I am having");
    Serial.println(nrOfCoin10, DEC);
    mCoin->SetCoin10(mappingCoin( nrOfCoin10));
  }
}

void CoinWallet::AddCoin50()
{
  if ( mCoin->GetCoin50Button() && nrOfCoin50 < 3)
  {
    nrOfCoin50++;
    mCoin->SetCoin50(mappingCoin(nrOfCoin50++));
  }
}

void CoinWallet::AddCoin200()
{
  if ( mCoin->GetCoin200Button() && nrOfCoin200 < 2)
  {
    nrOfCoin200++;
    mCoin->SetCoin200(mappingCoin(nrOfCoin200));
  }
}

void CoinWallet::WithdrawAll()
{
  if ( mCoin->GetClearButton())
  {
    nrOfCoin10 = 0;
    nrOfCoin50 = 0;
    nrOfCoin200 = 0;
    mCoin->SetCoin10(nrOfCoin10);
    mCoin->SetCoin50(nrOfCoin50);
    mCoin->SetCoin200(nrOfCoin200);
  }
}

char CoinWallet::mappingCoin(char nrofCoin)
{
  if (nrofCoin == 1)
  {
    return B00000001;
  }
  if (nrofCoin == 2)
  {
    return B00000011;
  }
  if (nrofCoin == 3)
  {
    return B00000111;
  }
}
CoinWallet::~CoinWallet()
{}

