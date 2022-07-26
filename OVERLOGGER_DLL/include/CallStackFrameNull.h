#pragma once

#include <string>

#include "ICallStackFrame.h"
#include "DllUtils.h"

namespace olg
{
    class CallStackFrameNull : public ICallStackFrame
    {
    public:
        virtual const std::string& getFunctionName() const override;
        virtual const std::string& getSourceFileName() const override;
        virtual unsigned long getCodeLine() const override;
        virtual unsigned long long getAddress() const override;
    };

    const std::string& getNullStdString();
}

extern "C"
{
    DLLEXPORT const olg::ICallStackFrame* getCallStackFrameNull();
    DLLEXPORT const char* getNullString();
}
