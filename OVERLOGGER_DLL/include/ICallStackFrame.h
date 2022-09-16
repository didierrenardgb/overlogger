#pragma once

#include <string>
#include "DllUtils.h"
#include <stdbool.h>

namespace olg
{
    class ICallStackFrame
    {
    public:
        virtual const std::string &getFunctionName() const = 0;
        virtual const std::string &getSourceFileName() const = 0;
        virtual unsigned long getCodeLine() const = 0;
        virtual unsigned long long getAddress() const = 0;
		virtual ~ICallStackFrame();
    };
}

extern "C" 
{
    DLLEXPORT bool equals(const olg::ICallStackFrame* cs1, const olg::ICallStackFrame* cs2);
}
