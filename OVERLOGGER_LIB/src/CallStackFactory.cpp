#include "CallStackFactory.h"
#include "CallStack.h"
#include "CallStackNull.h"

namespace olg
{

    std::unique_ptr<ICallStack> CallStackFactory::create(std::vector<std::unique_ptr<ICallStackFrame>> &&frames)
    {
        if (not frames.empty())
        {
            return std::make_unique<CallStack>(std::forward<std::vector<std::unique_ptr<ICallStackFrame>>>(frames));
        }
        return std::make_unique<CallStackNull>();
    }

}