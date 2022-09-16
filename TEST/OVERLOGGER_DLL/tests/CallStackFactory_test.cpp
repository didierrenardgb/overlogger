#include <gtest/gtest.h>
#include "ICallStack.h"
#include "CallStackFactory.h"
#include "CallStackFrame.h"
#include "CallStackFrameNull.h"

namespace olg::test 
{
    TEST(CallStackFactoryTest, ConstructionNoFrames) {
        using namespace olg;
        std::vector<std::unique_ptr<ICallStackFrame>> v;
        CallStackFactory csf = CallStackFactory{};
        std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
        EXPECT_NE(cs.get(), nullptr);
    }

    TEST(CallStackFactoryTest, ConstructionWithOneFrame) {
        using namespace olg;
        std::vector<std::unique_ptr<ICallStackFrame>> v;
        v.push_back(std::make_unique<CallStackFrame>(0u, "funName", "fileName", 0u));
        CallStackFactory csf = CallStackFactory{};
        std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
        EXPECT_NE(cs.get(), nullptr);
    }

    TEST(CallStackFactoryTest, ConstructionWithMultipleFrames) {
        using namespace olg;
        std::vector<std::unique_ptr<ICallStackFrame>> v;
        v.push_back(std::make_unique<CallStackFrame>(0u, "funName", "fileName", 0u));
        v.push_back(std::make_unique<CallStackFrame>(1u, "funName2", "fileName2", 1u));
        CallStackFactory csf = CallStackFactory{};
        std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
        EXPECT_NE(cs.get(), nullptr);
    }
    
    TEST(CallStackFactoryTest, ConstructionWithOneFrameNull) {
        using namespace olg;
        std::vector<std::unique_ptr<ICallStackFrame>> v;
        v.push_back(std::make_unique<CallStackFrameNull>());
        CallStackFactory csf = CallStackFactory{};
        std::unique_ptr<ICallStack> cs = csf.create(std::move(v));
        EXPECT_NE(cs.get(), nullptr);
    }

}