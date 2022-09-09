#include <gtest/gtest.h>
#include "CallStack.h"
#include "CallStackFactory.h"
#include "CallStackFrame.h"

TEST(CallStackTest, Construction) {
    //std::vector<std::unique_ptr<ICallStackFrame>> v;
    EXPECT_EQ(7 * 6, 42);
}