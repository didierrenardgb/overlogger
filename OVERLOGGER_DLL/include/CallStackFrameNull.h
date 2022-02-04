#pragma once

#include <string>
#include <chrono>

#include "ICallStackFrame.h"

namespace olg
{
    class CallStackFrameNull : public ICallStackFrame
    {
    public:
        virtual const std::string& getFunctionName() const override;
        virtual const std::string& getSourceFileName() const override;
        virtual unsigned long getCodeLine() const override;
        virtual std::chrono::milliseconds getTimestamp() const override;
    };
}