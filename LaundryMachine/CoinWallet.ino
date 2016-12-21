#include "CoinWallet.h"
CoinWallet::CoinWallet()
{
  nrOfCoin10 = 0;
  nrOfCoin50 = 0;
  nrOfCoin200 = 0;
}

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
  AddCoin50();
  AddCoin200();
  WithdrawAll();
  Serial.print("amount in wallet: ");Serial.println(CoinWallet::GetAmount());
}

int CoinWallet::GetAmount()
{
  balance = 10*nrOfCoin10 + 50*nrOfCoin50 + 200*nrOfCoin200;
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
  if (mCoin->GetCoin10Button())
  {
    if (nrOfCoin10 <= 3)
    {
      nrOfCoin10++;
    }
  }
  int coinIndicator = mappingCoin(nrOfCoin10);
  mCoin->SetCoin10(coinIndicator);
}

void CoinWallet::AddCoin50()
{
  if (mCoin->GetCoin50Button())
  {
    if (nrOfCoin50 <= 3)
    {
      nrOfCoin50++;
    }
  }
  int coinIndicator = mappingCoin(nrOfCoin50);
  mCoin->SetCoin50(coinIndicator);
}

void CoinWallet::AddCoin200()
{
   if (mCoin->GetCoin200Button())
  {
    if (nrOfCoin200 <= 2)
    {
      nrOfCoin200++;
    }
  }
  int coinIndicator = mappingCoin(nrOfCoin200);
  mCoin->SetCoin200(coinIndicator);
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
  else if (nrofCoin == 2)
  {
    return B00000011;
  }
  else if (nrofCoin == 3)
  {
    return B00000111;
  }
  else if (nrofCoin <= 0)
  {
    return B00000000;
  }
  else if (nrofCoin > 3)
  {
    return B00000111;
  }

}
CoinWallet::~CoinWallet()
{}

void CoinWallet::setInterface(ICoin* c)
{
  mCoin = c;
}

