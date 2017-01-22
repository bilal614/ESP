#include "TestProgramSelect.h"
#include "StubHardwareControl.h"
#include "ProgramSelect.h"

TestProgramSelect::TestProgramSelect()
{
    mProgram = new StubHardwareControl();
    mProgramSelect = new ProgramSelect(mProgram);
}

TestProgramSelect::~TestProgramSelect()
{

}
TEST_F(TestProgramSelect, getProgramA)
{
    //Default program is alway A
    char program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
}
TEST_F(TestProgramSelect, getProgramB)
{
    //Default program is alway A
    char program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'B');
}
TEST_F(TestProgramSelect, getProgramC)
{
    //Default program is alway A
    char program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'B');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'C');
}
TEST_F(TestProgramSelect, getProgram_backtoA)
{
    //Default program is alway A
    char program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'B');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'C');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
}
TEST_F(TestProgramSelect, getProgram_backtoB)
{
    //Default program is alway A
    char program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'B');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'C');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'B');
}
TEST_F(TestProgramSelect, getProgram_backtoC)
{
    //Default program is alway A
    char program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'B');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'C');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'A');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'B');
    mProgramSelect->Poll();
    program = mProgramSelect->GetProgramType();
    EXPECT_EQ(program, 'C');
}
