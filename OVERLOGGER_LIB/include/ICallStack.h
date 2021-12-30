#pragma once

#include <vector>
#include <memory>
#include "ICallStackFrame.h"

namespace olg
{
    class ICallStack
    {
    public:
        virtual size_t getSize() const = 0;
        virtual const ICallStackFrame &getFrame(size_t index) const = 0;
        virtual const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const = 0;
    };
}