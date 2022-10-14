#include "ICallStackFrame.h"

namespace olg
{
	ICallStackFrame::~ICallStackFrame() = default;
}

bool equalsFrame(const olg::ICallStackFrame* cs1, const olg::ICallStackFrame* cs2)
{
	return cs1->getAddress() == cs2->getAddress()
		&& cs1->getCodeLine() == cs2->getCodeLine()
		&& cs1->getFunctionName() == cs2->getFunctionName()
		&& cs1->getSourceFileName() == cs2->getSourceFileName();
}
