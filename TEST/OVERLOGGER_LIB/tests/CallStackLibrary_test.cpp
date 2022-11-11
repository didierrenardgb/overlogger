#include <gtest/gtest.h>
#include "CallStackLibrary.h"
#include "Overlogger.h"
#include "ICallStackRetriever.h"
#include "ICallStack.h"
#include "ICallStackFrame.h"

namespace olg::test
{
    TEST(CallStackLibraryTest, createCallStackRetriever)
    {
        olg::Overlogger overlogger;
        std::shared_ptr<olg::CallStackLibrary> csl = overlogger.callStackLibrary();
        ASSERT_NE(csl, nullptr);
        auto csr = csl->createCallStackRetriever();
        ASSERT_NE(csr.get(), nullptr);
        auto cs = csr->retrieve();
        ASSERT_NE(cs.get(), nullptr);
    }

    TEST(CallStackLibraryTest, getCallStackFrameNull)
    {
        olg::Overlogger overlogger;
        std::shared_ptr<olg::CallStackLibrary> csl = overlogger.callStackLibrary();
        ASSERT_NE(csl, nullptr);
        const ICallStackFrame& csf = csl->getCallStackFrameNull();
        EXPECT_EQ(csf.getAddress(), 0ull);
        EXPECT_EQ(csf.getCodeLine(), 0ul);
        EXPECT_EQ(csf.getFunctionName(), csl->getNullString());
        EXPECT_EQ(csf.getSourceFileName(), csl->getNullString());
    }

    TEST(CallStackLibraryTest, equals)
    {
        olg::Overlogger overlogger;
        std::shared_ptr<olg::CallStackLibrary> csl = overlogger.callStackLibrary();
        ASSERT_NE(csl, nullptr);
        auto csr = csl->createCallStackRetriever();
        ASSERT_NE(csr.get(), nullptr);
        auto cs = csr->retrieve();
        ASSERT_NE(cs.get(), nullptr);
        ASSERT_GE(cs->getSize(), 1);
        const auto& csframe0 = cs->getFrame(0);
        EXPECT_FALSE(csl->equals(csframe0, csl->getCallStackFrameNull()));
        EXPECT_TRUE(csl->equals(csl->getCallStackFrameNull(), csl->getCallStackFrameNull()));
    }

    TEST(CallStackLibraryTest, getNullString)
    {
        olg::Overlogger overlogger;
        std::shared_ptr<olg::CallStackLibrary> csl = overlogger.callStackLibrary();
        EXPECT_FALSE(csl->getNullString().empty());
        EXPECT_EQ(csl->getNullString(), csl->getNullString());
    }
}