#include <gtest/gtest.h>
#include "CallStackRetriever.h"
#include "CallStackFactory.h"

namespace olg::test
{
    // TODO: terminar de revisar este test. no compila

    TEST(CallStackRetrieverTest, retrieve)
    {
        CallStackRetriever csr{std::make_unique<CallStackFactory>()};
        // EXPECT_NE(csr.retrieve().get(), nullptr);
    }

    TEST(CallStackRetrieverTest, createCallStackRetriever)
    {
        auto csr_ptr = std::make_unique<ICallStackRetriever*>(createCallStackRetriever());
        // EXPECT_NE(csr_ptr->retrieve().get(), nullptr);
    }
}