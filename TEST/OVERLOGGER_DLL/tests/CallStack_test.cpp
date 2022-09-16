#include <gtest/gtest.h>
#include "CallStack.h"
#include "CallStackFactory.h"
#include "CallStackFrame.h"
#include "CallStackFrameNull.h"

namespace olg::test 
{
    bool isNull(const ICallStackFrame& csf) {
        CallStackFrameNull csfn{};
        return csfn.getAddress() == csf.getAddress()
            && csfn.getCodeLine() == csf.getCodeLine()
            && csfn.getFunctionName() == csf.getFunctionName()
            && csfn.getSourceFileName() == csf.getSourceFileName();
    }
        
    TEST(CallStackTest, ConstructionNoFrames) {
        using namespace olg;
        std::vector<std::unique_ptr<ICallStackFrame>> v;
        CallStackFactory csf = CallStackFactory{};
        std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
        EXPECT_EQ(cs->getSize(), 0);
        EXPECT_EQ(cs->getFrameList().size(), 0);
        EXPECT_TRUE(isNull(cs->getFrame(0)));
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