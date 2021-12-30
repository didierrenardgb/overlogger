#pragma once

#include <vector>
#include "ICallStack.h"

namespace olg
{
    class CallStack : public ICallStack
    {
    private:
        std::vector<std::unique_ptr<ICallStackFrame>> mCallStackFrames;
        CallStack(const std::vector<std::unique_ptr<ICallStackFrame>>& frames) : mCallStackFrames{frames} {};
        CallStack() = default;
        CallStack(const CallStack &cs) = delete;
        CallStack(CallStack &&cs) = delete;

        friend class CallStackFactory;

    public:
        virtual size_t getSize() const override;
        virtual const ICallStackFrame &getFrame(size_t index) const override;
        virtual const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const override;
    };
}