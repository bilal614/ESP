#include "CoinWallet.h"

CoinWallet::CoinWallet()
{
  nrOfCoin10 = 0;
  nrOfCoin50 = 0;
  nrOfCoin200 = 0;
  balance = 0;
}

CoinWallet::CoinWallet(ICoin * c)
{
  mCoin = c;
  nrOfCoin10 = 0;
  nrOfCoin50 = 0;
  nrOfCoin200 = 0;
  balance = 0;
}

void CoinWallet::Poll()
{
  AddCoin10();
  AddCoin50();
  AddCoin200();
  WithdrawAll();
  //Serial.print("amount in wallet: "); Serial.println(CoinWallet::GetAmount());
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
    return true;
  }
}

void CoinWallet:: AddCoin10()
{
  if (nrOfCoin10 < 3)
  {
    if (mCoin->GetCoin10Button())
    {
      nrOfCoin10++;
      int coinIndicator10 = mappingCoin(nrOfCoin10);
      mCoin->SetCoin10(coinIndicator10);
      balance += 10;
    }
  }

}

void CoinWallet::AddCoin50()
{
  if ( nrOfCoin50 < 3 && mCoin->GetCoin50Button())
  {
    nrOfCoin50++;
    int coinIndicator50 = mappingCoin(nrOfCoin50);
    mCoin->SetCoin50(coinIndicator50);
    balance += 50;

  }
}

void CoinWallet::AddCoin200()
{
  if (nrOfCoin200 < 2 && mCoin->GetCoin200Button())
  {
    nrOfCoin200++;
    int coinIndicator200 = mappingCoin(nrOfCoin200);
    mCoin->SetCoin200(coinIndicator200);
    balance += 200;
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
    balance = 0;
  }
}

void CoinWallet::ReturnChange()
{
  nrOfCoin10 = 0;
  nrOfCoin50 = 0;
  nrOfCoin200 = 0;
  mCoin->SetCoin10(nrOfCoin10);
  mCoin->SetCoin50(nrOfCoin50);
  mCoin->SetCoin200(nrOfCoin200);
}

char CoinWallet::mappingCoin(char nrofCoin)
{
  int result;
  if (nrofCoin == 1)
  {
    result = 0x01; //B00000001
  }
  else if (nrofCoin == 2)
  {
    result = 0x03; //B00000011
  }
  else if (nrofCoin == 3)
  {
    result = 0x07; //B00000111
  }
  else if (nrofCoin == 0)
  {
    result = 0x00; //B00000000
  }
  return result;
}
CoinWallet::~CoinWallet()
{}

void CoinWallet::setInterface(ICoin* c)
{
  mCoin = c;
}
