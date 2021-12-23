#pragma once

#include <vector>
#include "ICallStack.h"

namespace olg
{
    class CallStack : public ICallStack
    {
    private:
        std::vector<ICallStackFrame> mCallStackFrames;
        CallStack(const std::vector<ICallStackFrame>& frames) : mCallStackFrames{frames} {};
        CallStack() = default;
        CallStack(const CallStack &cs) = delete;
        CallStack(CallStack &&cs) = delete;

        friend class CallStackFactory;

    public:
        virtual size_t getSize() const override;
        virtual const ICallStackFrame &getFrame(size_t index) const override;
        virtual const std::vector<ICallStackFrame> &getFrameList() const override;
    };
}