#pragma once

#include <vector>
#include <memory>

#include <overlogger/dll/callstack/CallStack.h>

namespace olg
{
class ICallStackFrame;

class CallStack::CallStackImpl
{
public:
    CallStackImpl(std::vector<std::unique_ptr<ICallStackFrame>>&& frames);
    ~CallStackImpl();

    size_t getSize() const;

    ICallStackFrame const& getFrame(size_t index) const;
    std::vector<std::unique_ptr<ICallStackFrame>> const& getFrameList() const;

private:
    std::vector<std::unique_ptr<ICallStackFrame>> mCallStackFrames;
};
} // namespace olg
