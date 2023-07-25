#include <overlogger/dll/callstack/ICallStackFrame.h>

namespace olg
{
ICallStackFrame::~ICallStackFrame() = default;
} // namespace olg

bool equalsFrame(olg::ICallStackFrame const* cs1, olg::ICallStackFrame const* cs2)
{
	return cs1->getAddress() == cs2->getAddress()
		&& cs1->getCodeLine() == cs2->getCodeLine()
		&& cs1->getFunctionName() == cs2->getFunctionName()
		&& cs1->getSourceFileName() == cs2->getSourceFileName();
}
