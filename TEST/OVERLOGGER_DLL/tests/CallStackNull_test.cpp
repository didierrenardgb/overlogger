#include <gtest/gtest.h>
#include "CallStackNull.h"
#include "CallStackFactory.h"
#include "ICallStackFrame.h"
#include "CallStackFrameNull.h"

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
}