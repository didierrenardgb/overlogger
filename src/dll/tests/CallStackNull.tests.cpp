#include <gtest/gtest.h>

#include <overlogger/dll/callstack/CallStackNull.h>
#include <overlogger/dll/callstack/CallStackFactory.h>
#include <overlogger/dll/callstack/ICallStackFrame.h>
#include <overlogger/dll/callstack/CallStackFrameNull.h>

namespace olg::test
{
TEST(CallStackNullTest, ConstructionTest)
{
    CallStackFactory csf{};
    std::unique_ptr<ICallStack> cs = csf.create({});
    EXPECT_TRUE(equalsFrame(&cs->getFrame(0), getCallStackFrameNull()));
    EXPECT_EQ(0u, cs->getSize());
    EXPECT_EQ(0u, cs->getFrameList().size());
}
} // namespace olg::test
