#include "CallStackRetriever.h"
#include <Windows.h>

constexpr ULONG TRACE_MAX_STACK_FRAMES = 1024;
constexpr ULONG TRACE_MAX_FUNCTION_NAME_LENGTH = 1024;

namespace olg
{

    std::unique_ptr<ICallStack> CallStackRetriever::retrieve()
    {
        //CaptureStackBackTrace()
        return nullptr; //TODO.
    }

}