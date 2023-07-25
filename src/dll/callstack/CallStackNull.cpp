#include <overlogger/dll/callstack/CallStackNull.h>
#include <overlogger/dll/callstack/CallStackFrameNull.h>

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

ICallStackFrame const& CallStackNull::getFrame(size_t index) const
{
    return sNullFrame;
}

std::vector<std::unique_ptr<ICallStackFrame>> const& CallStackNull::getFrameList() const
{
    return sNullFrameList;
}
} // namespace olg
