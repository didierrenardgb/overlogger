#pragma once
#include "CallStack.h"

namespace olg
{
    class ICallStackRetriever
    {
    public:
        virtual CallStack retrieve() = 0;
    };
}