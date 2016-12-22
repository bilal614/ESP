#ifndef COINWALLET_H
#define COINWALLET_H

#include "ICoin.h"

class CoinWallet
{
  public:
    CoinWallet();
    CoinWallet(ICoin *);
    boolean Withdraw(int amount);
    void AddCoin10();
    void AddCoin50();
    void AddCoin200();
    int GetAmount();
    void Poll();
    void WithdrawAll();
    ~CoinWallet();
  private:
    ICoin * mCoin;
    char nrOfCoin10;
    char nrOfCoin50;
    char nrOfCoin200;
    int balance;
    //private methods
    char mappingCoin(char nrofCoin);
    void setInterface(ICoin* c);
};

#endif
