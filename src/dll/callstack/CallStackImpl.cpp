#include "CallStackImpl.h"

#include <overlogger/dll/callstack/ICallStackFrame.h>
#include <overlogger/dll/callstack/CallStackFrameNull.h>

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

ICallStackFrame const& CallStack::CallStackImpl::getFrame(size_t index) const
{
    if (index < getSize())
    {
        return *(mCallStackFrames[index]);
    }
    return sNullFrame;
}

std::vector<std::unique_ptr<ICallStackFrame>> const& CallStack::CallStackImpl::getFrameList() const
{
    return mCallStackFrames;
}
} // namespace olg
