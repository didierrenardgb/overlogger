#pragma once

#include <memory>

namespace olg
{
    class ICallStack;

    class ICallStackRetriever
    {
    public:
        virtual std::unique_ptr<ICallStack> retrieve() = 0;
    };
}