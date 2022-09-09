#pragma once

#include <memory>
#include <vector>

namespace olg
{
    class ICallStack;
    class ICallStackFrame;

    class ICallStackFactory
    {
    public:
        virtual std::unique_ptr<ICallStack> create(std::vector<std::unique_ptr<ICallStackFrame>> &&frames) = 0;
        virtual ~ICallStackFactory() = default;
    };
}