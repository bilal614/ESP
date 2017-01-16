#include "TestCoinWallet.h"
#include "StubHardwareControl.h"


TestCoinWallet::TestCoinWallet()
{
    mCoin = new StubHardwareControl();
    mCoinWallet = new CoinWallet(mCoin);
}

TestCoinWallet::~TestCoinWallet()
{
    delete mCoin;
    mCoin = NULL;
    delete mCoinWallet;
    mCoinWallet = NULL;
}

TEST_F(TestCoinWallet, test_coin10_zero)
{
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 0);
}
