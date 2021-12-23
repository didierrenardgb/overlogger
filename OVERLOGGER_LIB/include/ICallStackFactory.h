#pragma once

#include <memory>
#include "ICallStack.h"

namespace olg
{
    class ICallStackFactory
    {
    public:
        virtual std::unique_ptr<ICallStack> create(std::vector<ICallStackFrame> &&frames) = 0;
    };
}