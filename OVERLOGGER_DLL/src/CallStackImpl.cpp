#include "CallStackImpl.h"
#include "ICallStackFrame.h"
#include "CallStackFrameNull.h"

namespace olg
{
    static const olg::CallStackFrameNull sNullFrame;

    CallStack::CallStackImpl::CallStackImpl(std::vector<std::unique_ptr<ICallStackFrame>>&& frames)
    : mCallStackFrames{std::forward<std::vector<std::unique_ptr<ICallStackFrame>>>(frames)}
    {
    }

    CallStack::CallStackImpl::~CallStackImpl() = default;

    size_t CallStack::CallStackImpl::getSize() const
    {
        return mCallStackFrames.size();
    }

    const ICallStackFrame & CallStack::CallStackImpl::getFrame(size_t index) const
    {
        if (index < getSize())
        {
            return *(mCallStackFrames[index]);
        }
        return sNullFrame;
    }

    const std::vector<std::unique_ptr<ICallStackFrame>> & CallStack::CallStackImpl::getFrameList() const
    {
        return mCallStackFrames;
    }
}