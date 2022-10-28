#pragma once

#include <vector>
#include <memory>
#include "CallStack.h"

namespace olg
{
    class ICallStackFrame;

    class CallStack::CallStackImpl
    {
    public:
        CallStackImpl(std::vector<std::unique_ptr<ICallStackFrame>>&& frames);
        ~CallStackImpl();
        size_t getSize() const;
        const ICallStackFrame &getFrame(size_t index) const;
        const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const;
    private:
        std::vector<std::unique_ptr<ICallStackFrame>> mCallStackFrames;
    };
}