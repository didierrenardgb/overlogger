#include <Windows.h>
#include <dbghelp.h>

#include "ICallStack.h"
#include "CallStackRetriever.h"
#include "CallStackFactory.h"
#include "CallStackFrame.h"
#include "CallStackFrameNull.h"
#include <iostream>
#include <mutex>

constexpr ULONG TRACE_MAX_STACK_FRAMES = 64;

namespace olg
{
    // TODO: dbghelp.h no es Thread safe.
    // TODO: pensar si hay alguna forma de "decorar" esos metodos con templates, para que use el mutex

    /*
    static std::mutex m;

    static HANDLE __stdcall tsGetCurrentProcess() {
        std::unique_lock<std::mutex> lck{ m };
        return GetCurrentProcess();
    }
    */
    /*
    SymInitialize
    SymCleanup
    SymFromAddr
    SymGetLineFromAddr64
    */

    /*
    GetCurrentProcess
    CaptureStackBackTrace
    */

    static std::mutex m;

    template<typename F, typename... Args>
    auto CallWithMutex(F fun, Args&&... args) {
        std::lock_guard<std::mutex> lck{ m };
        return fun(std::forward<Args>(args)...);
    }

    class CallStackRetrieverImpl {
    public:
        HANDLE mProcessHandle;
        std::unique_ptr<ICallStackFactory> mCallStackFactory;
        CallStackRetrieverImpl(std::unique_ptr<ICallStackFactory>&& callStackFactory)
            : mCallStackFactory{ std::move(callStackFactory) }, mProcessHandle{ GetCurrentProcess() }
        {
            CallWithMutex(SymInitialize, mProcessHandle, PCSTR{}, TRUE);
        }
    };

    CallStackRetriever::CallStackRetriever(std::unique_ptr<ICallStackFactory>&& callStackFactory)
        : mImpl{ std::make_unique<CallStackRetrieverImpl>(std::move(callStackFactory)) }
    {}

    CallStackRetriever::~CallStackRetriever()
    {
        CallWithMutex(SymCleanup, mImpl->mProcessHandle);
        mImpl->mProcessHandle = nullptr;
    }

    std::unique_ptr<ICallStack> CallStackRetriever::retrieve()
    {
        //{ this buffers are reused on each iteration, and shouldn't be moved inside the loop, without being careful... (Specially DWORD displacement !)
        PVOID backTrace[TRACE_MAX_STACK_FRAMES];
        WORD numberOfFrames = CaptureStackBackTrace(0, TRACE_MAX_STACK_FRAMES, backTrace, NULL);

        TCHAR buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)]{};
        PSYMBOL_INFO pSymbol = reinterpret_cast<PSYMBOL_INFO>(buffer);
        pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        pSymbol->MaxNameLen = MAX_SYM_NAME;

        DWORD displacement{};
        IMAGEHLP_LINE64 line{};
        line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
        //}

        std::vector<std::unique_ptr<ICallStackFrame>> frames;

        for (WORD i = 0; i < numberOfFrames; ++i)
        {
            const DWORD64 address = reinterpret_cast<DWORD64>(backTrace[i]);
            if (TRUE != CallWithMutex(SymFromAddr, mImpl->mProcessHandle, address, PDWORD64{}, pSymbol))
            {
                std::cerr << "SymFromAddr - GetLastError: " << GetLastError() << std::endl; // TODO
            }
            if (TRUE != CallWithMutex(SymGetLineFromAddr64, mImpl->mProcessHandle, address, &displacement, &line))
            {
                line.LineNumber = 0;
                std::cerr << "GetLastError: " << GetLastError() << std::endl; // TODO
            }
            frames.push_back(std::make_unique<CallStackFrame>(pSymbol->Address, std::string(pSymbol->Name), line.FileName, line.LineNumber));
        }

        return mImpl->mCallStackFactory->create(std::move(frames));
    }

}

olg::ICallStackRetriever* createCallStackRetriever()
{
	return new olg::CallStackRetriever{ std::make_unique<olg::CallStackFactory>() };
}
