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

TEST_F(TestCoinWallet, test_coin10_one)
{
    mCoinWallet->AddCoin10();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 10);
}

TEST_F(TestCoinWallet, test_coin10_two)
{
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin10();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 20);
}

