#pragma once

#include <string>

#include "ICallStackFrame.h"

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
}