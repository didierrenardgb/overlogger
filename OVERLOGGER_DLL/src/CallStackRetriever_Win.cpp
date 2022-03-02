#include <Windows.h>
#include <dbghelp.h>

#include "ICallStack.h"
#include "CallStackRetriever.h"
#include "CallStackFactory.h"
#include "CallStackFrame.h"
#include "CallStackFrameNull.h"
#include <iostream>

constexpr ULONG TRACE_MAX_STACK_FRAMES = 64;

namespace olg
{
    class CallStackRetrieverImpl {
    public:
        HANDLE mProcessHandle;
        std::unique_ptr<ICallStackFactory> mCallStackFactory;
        CallStackRetrieverImpl(std::unique_ptr<ICallStackFactory>&& callStackFactory)
            : mCallStackFactory{ std::move(callStackFactory) }, mProcessHandle{ GetCurrentProcess() }
        {
            SymInitialize(mProcessHandle, NULL, TRUE);
        }
    };

    CallStackRetriever::CallStackRetriever(std::unique_ptr<ICallStackFactory>&& callStackFactory)
        : mImpl{ std::make_unique<CallStackRetrieverImpl>(std::move(callStackFactory)) }
    {}

    CallStackRetriever::~CallStackRetriever()
    {
        SymCleanup(mImpl->mProcessHandle);
        mImpl->mProcessHandle = nullptr;
    }

    std::unique_ptr<ICallStack> CallStackRetriever::retrieve()
    {
        PVOID backTrace[TRACE_MAX_STACK_FRAMES];
        WORD numberOfFrames = CaptureStackBackTrace(0, TRACE_MAX_STACK_FRAMES, backTrace, NULL);

        char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
        PSYMBOL_INFO pSymbol = reinterpret_cast<PSYMBOL_INFO>(buffer);
        pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        pSymbol->MaxNameLen = MAX_SYM_NAME;

        std::vector<std::unique_ptr<ICallStackFrame>> frames;

        for (int i = 0; i < numberOfFrames; i++)
        {
            std::unique_ptr<ICallStackFrame> frame;

            DWORD64 address = (DWORD64)(backTrace[i]);
            if (TRUE != SymFromAddr(mImpl->mProcessHandle, address, NULL, pSymbol))
            {
                int ret = GetLastError();
                std::cerr << "SymFromAddr - GetLastError: " << ret << std::endl;
            }

            DWORD displacement;
            IMAGEHLP_LINE64 line;
            line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);

            if (SymGetLineFromAddr64(mImpl->mProcessHandle, address, &displacement, &line))
            {
                frame = std::make_unique<CallStackFrame>(pSymbol->Address, std::string(pSymbol->Name), line.FileName, line.LineNumber);
            }
            else
            {
                int ret = GetLastError();
                std::cerr << "GetLastError: " << ret << std::endl;
                frame = std::make_unique<CallStackFrameNull>();
            }
            frames.push_back(std::move(frame));
        }

        return mImpl->mCallStackFactory->create(std::move(frames));
    }

}