#ifndef TESTPROGRAMSELECT_H
#define TESTPROGRAMSELECT_H

#include "ArduinoWrapper.h"	// to be included before all other LaundryMachine include files

#include "StubHardwareControl.h"
#include "ProgramSelect.h"

#include "gtest/gtest.h"

class TestProgramSelect : public ::testing::Test
{
    public:
        TestProgramSelect();
        virtual ~TestProgramSelect();
    protected:
        /// they must be protected instead of private, because Google Test makes subclasses for the tests
        ProgramSelect *         mProgramSelect;
        StubHardwareControl *   mProgram;
    private:
};

#endif // TestProgramSelect_H
