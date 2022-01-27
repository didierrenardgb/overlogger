#include "CallStackNull.h"

#include "CallStackFrameNull.h"

namespace
{
    inline olg::CallStackFrameNull gNullFrame;
    inline std::vector<std::unique_ptr<olg::ICallStackFrame>> gNullFrameList;
}

namespace olg
{

    const ICallStackFrame& CallStackNull::getFrame(size_t index) const
    {
        return gNullFrame;
    }

    const std::vector<std::unique_ptr<ICallStackFrame>>& CallStackNull::getFrameList() const
    {
        return gNullFrameList;
    }
}