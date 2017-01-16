#include "TestCoinWallet.h"
#include "StubHardwareControl.h"


TestCoinWallet::TestCoinWallet()
{
    mCoin = new StubHardwareControl();
    mCoinWallet = new CoinWallet(mCoin);
}

TestCoinWallet::~TestCoinWallet()
{
    //dtor
}

TEST_F(TestCoinWallet, test_coin10)
{
    EXPECT_EQ(10, 10);
}
