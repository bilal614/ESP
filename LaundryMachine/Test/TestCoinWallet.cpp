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
TEST_F(TestCoinWallet, test_getBalance)
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

TEST_F(TestCoinWallet, test_coin10_three)
{
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin10();
    int  balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 30);
}

TEST_F(TestCoinWallet, test_coin10_four)
{
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin10();
    int  balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 30);
}

TEST_F(TestCoinWallet, test_coin50_one)
{
    mCoinWallet->AddCoin50();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 50);
}

TEST_F(TestCoinWallet, test_coin50_two)
{
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 100);
}

TEST_F(TestCoinWallet, test_coin50_three)
{
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    int  balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 150);
}

TEST_F(TestCoinWallet, test_coin50_four)
{
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    int  balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 150);
}

TEST_F(TestCoinWallet, test_coin200_one)
{
    mCoinWallet->AddCoin200();
    int  balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 200);
}

TEST_F(TestCoinWallet, test_coin200_two)
{
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin200();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance,400);
}


TEST_F(TestCoinWallet, test_coin200_three)
{
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin200();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance,400);
}

TEST_F(TestCoinWallet, test_balance_programA)
{
    //Added 1 coin of 200, 3 coins of 50 and 1 coin 10  ---> 360
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin200();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 360);
}

TEST_F(TestCoinWallet, test_balance_programB)
{
    //Added 2 coins of 200, 1 coin of 50 and 3 coins of 10 ---> 480
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin200();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 480);
}

TEST_F(TestCoinWallet, test_balance_programC)
{
    //Added 2 coins of 200, 2 coins of 50 and  coins of 10 ---> 510
    mCoinWallet->AddCoin10();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin200();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 510);
}
TEST_F(TestCoinWallet, test_withdraw_all)//Withdraw the specific amount of money
{
    //Put in 550
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 550);
    //Assume that the washing program C is taken
    mCoinWallet->WithdrawAll();
    balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 0);
}

TEST_F(TestCoinWallet, test_withdraw)//Withdraw the specific amount of money
{
    //Put in 550
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin200();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    mCoinWallet->AddCoin50();
    int balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 550);
    //Assume that the washing program C is taken
    boolean result = mCoinWallet->Withdraw(510);
    ASSERT_TRUE(result);
    balance = mCoinWallet->GetAmount();
    EXPECT_EQ(balance, 40);
}

