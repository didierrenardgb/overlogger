#pragma once

#include "ICallStackRetriever.h"

namespace olg
{
    class CallStackRetriever : public ICallStackRetriever
    {
        virtual std::unique_ptr<ICallStack> retrieve();
    };
}