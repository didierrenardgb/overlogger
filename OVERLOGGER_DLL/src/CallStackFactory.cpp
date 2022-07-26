#include "CallStackFactory.h"
#include "CallStack.h"
#include "CallStackNull.h"

namespace olg
{

    std::unique_ptr<ICallStack> CallStackFactory::create(std::vector<std::unique_ptr<ICallStackFrame>> &&frames)
    {
        if (!frames.empty())
        {
            return CallStack::makeUnique(std::forward<std::vector<std::unique_ptr<ICallStackFrame>>>(frames));
        }
        return CallStackNull::makeUnique();
    }

}
