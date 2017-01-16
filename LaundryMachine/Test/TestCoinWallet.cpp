#include "TestCoinWallet.h"
#include "StubHardwareControl.h"
#include "CoinWallet.h"

TestCoinWallet::TestCoinWallet()
{
    mCoin = new StubHardwareControl();
    mCoinWallet = new CoinWallet(mCoin);
}

TestCoinWallet::~TestCoinWallet()
{

}

TEST_F(TestCoinWallet, test_coin10_zero)
{
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 0);
}
