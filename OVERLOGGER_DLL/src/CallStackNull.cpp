#include "CallStackNull.h"
#include "CallStackFrameNull.h"

namespace olg
{
	CallStackNull::CallStackNull() = default;
    static const olg::CallStackFrameNull sNullFrame;
    static const std::vector<std::unique_ptr<olg::ICallStackFrame>> sNullFrameList;

	std::unique_ptr<ICallStack> CallStackNull::makeUnique()
	{
		return std::unique_ptr<CallStackNull>(new CallStackNull());
	}

	size_t CallStackNull::getSize() const
	{ 
		return 0u; 
	};

    const ICallStackFrame& CallStackNull::getFrame(size_t index) const
    {
        return sNullFrame;
    }

    const std::vector<std::unique_ptr<ICallStackFrame>>& CallStackNull::getFrameList() const
    {
        return sNullFrameList;
    }
}
