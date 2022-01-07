#pragma once
#include "ICallStack.h"
#include "memory"

namespace olg
{
    class ICallStackRetriever
    {
    public:
        virtual std::unique_ptr<ICallStack> retrieve() = 0;
    };
}