#pragma once

#include "ICallStackFactory.h"

namespace olg
{
    class CallStackFactory : public ICallStackFactory
    {
    public:
        virtual std::unique_ptr<ICallStack> create(std::vector<std::unique_ptr<ICallStackFrame>> &&frames) override;
    };
}