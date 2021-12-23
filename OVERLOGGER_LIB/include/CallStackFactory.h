#pragma once

#include "ICallStackFactory.h"

namespace olg
{
    class CallStackFactory : public ICallStackFactory
    {
    public:
        virtual std::unique_ptr<ICallStack> create(std::vector<ICallStackFrame> &&frames) override;
    };
}