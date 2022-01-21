#pragma once

#include <vector>
#include <memory>

namespace olg
{
    class ICallStackFrame;

    class ICallStack
    {
    public:
        virtual ~ICallStack() = default;
        virtual size_t getSize() const = 0;
        virtual const ICallStackFrame &getFrame(size_t index) const = 0;
        virtual const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const = 0;
    };
}