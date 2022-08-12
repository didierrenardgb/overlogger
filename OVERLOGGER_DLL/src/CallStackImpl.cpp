#include "CallStackImpl.h"
#include "ICallStackFrame.h"
#include "CallStackFrameNull.h"

namespace olg
{
    static const olg::CallStackFrameNull sNullFrame;

    CallStackImpl::CallStackImpl(std::vector<std::unique_ptr<ICallStackFrame>>&& frames)
    : mCallStackFrames{std::forward<std::vector<std::unique_ptr<ICallStackFrame>>>(frames)}
    {
    }

    CallStackImpl::~CallStackImpl() = default;

    size_t CallStackImpl::getSize() const
    {
        return mCallStackFrames.size();
    }

    const ICallStackFrame &CallStackImpl::getFrame(size_t index) const
    {
        if (index < getSize())
        {
            return *(mCallStackFrames[index]);
        }
        return sNullFrame;
    }

    const std::vector<std::unique_ptr<ICallStackFrame>> &CallStackImpl::getFrameList() const
    {
        return mCallStackFrames;
    }
}