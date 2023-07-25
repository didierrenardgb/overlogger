#include <gtest/gtest.h>

#include <overlogger/dll/callstack/CallStackFrame.h>

namespace olg::test
{
TEST(ICallStackFrameTest, equalsFrame_sameFrame)
{
    CallStackFrame csf{ 0x1000, "myTestFunName", "mySrcFileName", 0x500 };
    EXPECT_TRUE(equalsFrame(&csf, &csf));
}

TEST(ICallStackFrameTest, equalsFrame_differentFrames)
{
    CallStackFrame csf1{ 0x1000, "myTestFunName", "mySrcFileName", 0x500 };
    CallStackFrame csf2{ 0x1001, "myTestFunName2", "mySrcFileName", 0x500 };
    EXPECT_FALSE(equalsFrame(&csf1, &csf2));
}
} // namespace olg::test
