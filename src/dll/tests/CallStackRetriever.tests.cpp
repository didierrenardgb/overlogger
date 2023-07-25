#include <gtest/gtest.h>

#include <overlogger/dll/callstack/ICallStack.h>
#include <overlogger/dll/callstack/CallStackRetriever.h>
#include <overlogger/dll/callstack/CallStackFactory.h>

namespace olg::test
{   
TEST(CallStackRetrieverTest, retrieve)
{
    CallStackRetriever csr{std::make_unique<CallStackFactory>()};
    ASSERT_NE(csr.retrieve().get(), nullptr);
}

TEST(CallStackRetrieverTest, createCallStackRetriever)
{
    auto csr_ptr = std::unique_ptr<ICallStackRetriever>(createCallStackRetriever());
    ASSERT_NE(csr_ptr->retrieve().get(), nullptr);
    EXPECT_NE(csr_ptr->retrieve()->getSize(), 0u);
}
} // namespace olg::test
