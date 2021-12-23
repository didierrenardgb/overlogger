#include "CallStackFactory.h"
#include "CallStack.h"
#include "CallStackNull.h"

namespace olg
{

    std::unique_ptr<ICallStack> CallStackFactory::create(std::vector<ICallStackFrame> &&frames)
    {
        if (not frames.empty())
        {
            return std::make_unique<CallStack>(std::forward<std::vector<ICallStackFrame>>(frames)); // std::move 
        }
        return std::make_unique<CallStackNull>();
    }

}