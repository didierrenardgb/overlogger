#include <execinfo.h>
#include <dlfcn.h>
#include <cxxabi.h>

#include "ICallStack.h"
#include "CallStackRetriever.h"
#include "CallStackFactory.h"
#include "CallStackFrame.h"
#include "CallStackFrameNull.h"
#include <iostream>

constexpr unsigned int TRACE_MAX_STACK_FRAMES = 64;

namespace olg
{
    class CallStackRetrieverImpl {
    public:
        std::unique_ptr<ICallStackFactory> mCallStackFactory;
        CallStackRetrieverImpl(std::unique_ptr<ICallStackFactory>&& callStackFactory)
            : mCallStackFactory{ std::move(callStackFactory) }
        {}
    };

    CallStackRetriever::CallStackRetriever(std::unique_ptr<ICallStackFactory>&& callStackFactory)
        : mImpl{ std::make_unique<CallStackRetrieverImpl>(std::move(callStackFactory)) }
    {}

    CallStackRetriever::~CallStackRetriever()
    {
    }

    std::unique_ptr<ICallStack> CallStackRetriever::retrieve()
    {
        void* callstack[TRACE_MAX_STACK_FRAMES] { 0 };
        const int numberOfFrames = backtrace(callstack, TRACE_MAX_STACK_FRAMES);
        char** symbols = backtrace_symbols(callstack, numberOfFrames);

        if (symbols == nullptr)
        {
            std::cerr << "Error when retrieving backstrace_symbols\n";
            return nullptr;
        }

        std::vector<std::unique_ptr<ICallStackFrame>> frames;

        for (int i = 0; i < numberOfFrames; i++)
        {
            std::unique_ptr<ICallStackFrame> frame;

            // TODO: ver de donde sacar filename y linenumber

            Dl_info info; //TODO: ver que trae este DL_info. https://man7.org/linux/man-pages/man3/dladdr.3.html
            if (dladdr(callstack[i], &info) != 0 && info.dli_sname != nullptr)
            {
                int status = 0;
                char* demangled = abi::__cxa_demangle(info.dli_sname, nullptr, 0, &status);
                std::string functionName = (status == 0 && demangled != nullptr) ? demangled : info.dli_sname;
                frame = std::make_unique<CallStackFrame>(reinterpret_cast<unsigned long long>(callstack[i]), functionName, /*line.FileName*/ "", /*line.LineNumber*/ 0);
                if(demangled != nullptr)
                {
                    free(demangled);
                }
            }
            else
            {
                frame = std::make_unique<CallStackFrame>(reinterpret_cast<unsigned long long>(callstack[i]), "NO NAME INFO", /*line.FileName*/ "", /*line.LineNumber*/ 0);
            }
            frames.push_back(std::move(frame));
        }

        free(symbols);
        return mImpl->mCallStackFactory->create(std::move(frames));
    }

}

olg::ICallStackRetriever* createCallStackRetriever()
{
    return new olg::CallStackRetriever{ std::make_unique<olg::CallStackFactory>() };
}
