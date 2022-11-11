#include <gtest/gtest.h>
#include "CallStackFrameNull.h"
#include "ICallStackFrame.h"

namespace olg::test
{
    TEST(CallStackFrameNullTest, ConstructionAndGettersTest)
    {
        CallStackFrameNull csfn{};
        EXPECT_EQ(0ull, csfn.getAddress());
        EXPECT_EQ(olg::getNullStdString(), csfn.getFunctionName());
        EXPECT_EQ(olg::getNullStdString(), csfn.getSourceFileName());
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
        EXPECT_EQ(olg::getNullStdString(), csfn.getFunctionName());
        EXPECT_EQ(olg::getNullStdString(), csfn.getSourceFileName());
        EXPECT_EQ(0ul, csfn.getCodeLine());
    }

    TEST(CallStackFrameNullTest, getNullString)
    {
        EXPECT_EQ(getNullString(), olg::getNullStdString().c_str());
        EXPECT_EQ(0, strcmp(getNullString(), olg::getNullStdString().c_str()));
    }
}