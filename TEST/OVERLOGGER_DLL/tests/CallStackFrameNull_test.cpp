#include <gtest/gtest.h>
#include "CallStackFrameNull.h"
#include "ICallStackFrame.h"

namespace olg::test
{
    TEST(CallStackFrameNullTest, ConstructionAndGettersTest)
    {
        CallStackFrameNull csfn{};
        EXPECT_EQ(0ull, csfn.getAddress());
        EXPECT_EQ(olg::getNullString(), csfn.getFunctionName());
        EXPECT_EQ(olg::getNullString(), csfn.getSourceFileName());
        EXPECT_EQ(0ul, csfn.getCodeLine());
    }

    TEST(CallStackFrameNullTest, getCallStackFrameNull_isSame)
    {
        EXPECT_EQ(getCallStackFrameNull(), getCallStackFrameNull());
        EXPECT_TRUE(equalsFrame(getCallStackFrameNull(), getCallStackFrameNull()));
    }

    TEST(CallStackFrameNullTest, getCallStackFrameNull)
    {
        const ICallStackFrame* csfn_ptr = getCallStackFrameNull();
        const CallStackFrameNull csfn = *static_cast<const CallStackFrameNull*>(csfn_ptr);
        EXPECT_EQ(0ull, csfn.getAddress());
        EXPECT_EQ(olg::getNullString(), csfn.getFunctionName());
        EXPECT_EQ(olg::getNullString(), csfn.getSourceFileName());
        EXPECT_EQ(0ul, csfn.getCodeLine());
    }
}