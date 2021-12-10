#pragma once

#include <vector>
#include "CallStackFrame.h"

// TODO: ICallStack
// TODO: CallStackNull
// TODO: namespaces

class CallStack
{
private:
    std::vector<CallStackFrame> mCallStackFrames;
    CallStack() = default;
    friend class CallStackFactory;
};