#include "CallStackNull.h"
#include "CallStackFrameNull.h"

namespace olg
{

    const ICallStackFrame& CallStackNull::getFrame(size_t index) const
    {
        static const olg::CallStackFrameNull gNullFrame;
        return gNullFrame;
    }

    const std::vector<std::unique_ptr<ICallStackFrame>>& CallStackNull::getFrameList() const
    {
        static const std::vector<std::unique_ptr<olg::ICallStackFrame>> gNullFrameList;
        return gNullFrameList;
    }
}