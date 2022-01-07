#pragma once

#include <vector>
#include "ICallStack.h"

namespace olg
{
    class CallStackImpl
    {
    private:
        std::vector<std::unique_ptr<ICallStackFrame>> mCallStackFrames;
    public:
        CallStackImpl(std::vector<std::unique_ptr<ICallStackFrame>>&& frames);
        size_t getSize() const;
        const ICallStackFrame &getFrame(size_t index) const;
        const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const;
    };
}