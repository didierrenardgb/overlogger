#include "CallStack.h"

namespace olg
{
    size_t CallStack::getSize() const
    {
        return mCallStackFrames.size();
    }
    const ICallStackFrame &CallStack::getFrame(size_t index) const
    {
        return *(mCallStackFrames[index]);
    }
    const std::vector<std::unique_ptr<ICallStackFrame>> &CallStack::getFrameList() const
    {
        return mCallStackFrames;
    }

}