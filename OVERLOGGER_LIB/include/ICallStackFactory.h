#pragma once

#include <memory>
#include "ICallStack.h"

namespace olg
{
    class ICallStackFactory
    {
    public:
        virtual std::unique_ptr<ICallStack> create(std::vector<std::unique_ptr<ICallStackFrame>> &&frames) = 0;
    };
}