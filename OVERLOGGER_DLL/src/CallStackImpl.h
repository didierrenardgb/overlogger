#pragma once

#include <vector>
#include <memory>

namespace olg
{
    class ICallStackFrame;

    class CallStackImpl
    {
    private:
        std::vector<std::unique_ptr<ICallStackFrame>> mCallStackFrames;
    public:
        CallStackImpl(std::vector<std::unique_ptr<ICallStackFrame>>&& frames);
        ~CallStackImpl();
        size_t getSize() const;
        const ICallStackFrame &getFrame(size_t index) const;
        const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const;
    };
}