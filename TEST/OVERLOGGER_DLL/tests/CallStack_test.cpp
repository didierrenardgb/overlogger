#include <gtest/gtest.h>
#include "CallStack.h"
#include "CallStackFactory.h"
#include "CallStackFrame.h"
#include "CallStackFrameNull.h"
#include "ICallStackFrame.h"

namespace olg::test 
{     
    TEST(CallStackTest, ConstructionNoFrames) {
        using namespace olg;
		CallStackFrameNull csfn{};
        std::vector<std::unique_ptr<ICallStackFrame>> v;
        CallStackFactory csf = CallStackFactory{};
        std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
        EXPECT_EQ(cs->getSize(), 0);
        EXPECT_EQ(cs->getFrameList().size(), 0);
        EXPECT_TRUE(equalsFrame(&cs->getFrame(0), &csfn));
    }
}

/*
TEST(CallStackTest, ConstructionWithOneFrame) {
    using namespace olg;
    std::vector<std::unique_ptr<ICallStackFrame>> v;
    v.push_back(std::make_unique<CallStackFrame>(0u, "funName", "fileName", 0u));
    CallStackFactory csf = CallStackFactory{};
    std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
    EXPECT_NE(cs.get(), nullptr);
}

TEST(CallStackTest, ConstructionWithMultipleFrames) {
    using namespace olg;
    std::vector<std::unique_ptr<ICallStackFrame>> v;
    v.push_back(std::make_unique<CallStackFrame>(0u, "funName", "fileName", 0u));
    v.push_back(std::make_unique<CallStackFrame>(1u, "funName2", "fileName2", 1u));
    CallStackFactory csf = CallStackFactory{};
    std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
    EXPECT_NE(cs.get(), nullptr);
}

TEST(CallStackTest, ConstructionWithOneFrameNull) {
    using namespace olg;
    std::vector<std::unique_ptr<ICallStackFrame>> v;
    v.push_back(std::make_unique<CallStackFrameNull>());
    CallStackFactory csf = CallStackFactory{};
    std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
    EXPECT_NE(cs.get(), nullptr);
}
*/