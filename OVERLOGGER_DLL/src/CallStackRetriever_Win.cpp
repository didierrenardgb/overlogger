#include <Windows.h>
#include <dbghelp.h>

#include "CallStackRetriever.h"
#include "CallStackFactory.h"
#include "CallStackFrame.h"
#include "CallStackFrameNull.h"

constexpr ULONG TRACE_MAX_STACK_FRAMES = 64;
constexpr ULONG TRACE_MAX_FUNCTION_NAME_LENGTH = 1024;

namespace olg
{

    CallStackRetriever::CallStackRetriever(std::unique_ptr<ICallStackFactory>&& callStackFactory)
        : mCallStackFactory{std::move(callStackFactory)}
    {
        mProcessHandle = GetCurrentProcess();
        SymInitialize(mProcessHandle, NULL, TRUE);
    }

    CallStackRetriever::~CallStackRetriever()
    {
        SymCleanup(mProcessHandle);
        mProcessHandle = nullptr;
    }

    std::unique_ptr<ICallStack> CallStackRetriever::retrieve()
    {
        PVOID backTrace[TRACE_MAX_STACK_FRAMES];
        WORD numberOfFrames = CaptureStackBackTrace(0, TRACE_MAX_STACK_FRAMES, backTrace, NULL);
        SYMBOL_INFO sinfo;
        sinfo.MaxNameLen = TRACE_MAX_FUNCTION_NAME_LENGTH;
        sinfo.SizeOfStruct = sizeof(SYMBOL_INFO);

        IMAGEHLP_LINE64 line;
        DWORD displacement;
        line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
        
        
        std::vector<std::unique_ptr<ICallStackFrame>> frames;

        for (int i = 0; i < numberOfFrames; i++)
        {
            std::unique_ptr<ICallStackFrame> frame;
            DWORD64 address = (DWORD64)(backTrace[i]);
            SymFromAddr(mProcessHandle, address, NULL, &sinfo);
            if (SymGetLineFromAddr64(mProcessHandle, address, &displacement, &line))
            {
                /// CHAR SYMBOL_INFO::Name[1] ???
                frame = std::make_unique<CallStackFrame>(std::to_string(sinfo.Address) + ">" + std::string(sinfo.Name), line.FileName, line.LineNumber);
            }
            else
            {
                frame = std::make_unique<CallStackFrameNull>();
            }
            frames.push_back(std::move(frame));
        }

        return mCallStackFactory->create(std::move(frames));
    }

}