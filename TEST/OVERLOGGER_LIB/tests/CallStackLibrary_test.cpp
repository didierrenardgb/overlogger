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
        //TODO: "OLG::NULL"
        const std::string nullString = "OLG::NULL";
        olg::Overlogger overlogger;
        std::shared_ptr<olg::CallStackLibrary> csl = overlogger.callStackLibrary();
        ASSERT_NE(csl, nullptr);
        const ICallStackFrame& csf = csl->getCallStackFrameNull();
        EXPECT_EQ(csf.getAddress(), 0ull);
        EXPECT_EQ(csf.getCodeLine(), 0ul);
        EXPECT_EQ(csf.getFunctionName(), nullString);
        EXPECT_EQ(csf.getSourceFileName(), nullString);
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
}