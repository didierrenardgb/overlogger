#include "CallStack.h"
#include "CallStackImpl.h"

namespace olg
{
    std::unique_ptr<ICallStack> CallStack::makeUnique(std::vector<std::unique_ptr<ICallStackFrame>>&& frames)
    {
        return std::unique_ptr<ICallStack>(new CallStack(std::forward<std::vector<std::unique_ptr<ICallStackFrame>>>(frames)));
    }

    size_t CallStack::getSize() const
    {
        return mCallStackImpl->getSize();
    }
    const ICallStackFrame& CallStack::getFrame(size_t index) const
    {
        return mCallStackImpl->getFrame(index);
    }
    const std::vector<std::unique_ptr<ICallStackFrame>>& CallStack::getFrameList() const
    {
        return mCallStackImpl->getFrameList();
    }

    CallStack::CallStack(std::vector<std::unique_ptr<ICallStackFrame>>&& frames)
        : mCallStackImpl(std::make_unique<CallStackImpl>(std::move(frames)))
    {

    }

    CallStack::~CallStack() {}
}