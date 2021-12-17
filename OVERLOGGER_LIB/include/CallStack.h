#pragma once

#include <vector>
#include "ICallStack.h"

// TODO: namespaces

class CallStack : public ICallStack
{
private:
    std::vector<ICallStackFrame> mCallStackFrames;
    CallStack() = default;
    CallStack(const CallStack& cs) = delete;
    CallStack(CallStack&& cs) = delete;

    friend class CallStackFactory;

public:
    virtual size_t getSize() const override;
    virtual const ICallStackFrame &getFrame(size_t index) const override;
    virtual const std::vector<ICallStackFrame> &getFrameList() const override;
};