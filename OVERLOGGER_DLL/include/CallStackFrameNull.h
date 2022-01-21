#pragma once

#include <string>
#include <chrono>

#include "ICallStackFrame.h"

namespace olg
{
    class CallStackFrameNull : public ICallStackFrame
    {
    private:
        inline static const std::string sFunctionName = "?NULL";
        inline static const std::string sSourceFileName = "?NULL";

    public:
        virtual const std::string &getFunctionName() const override
        {
            return sFunctionName;
        }

        virtual const std::string &getSourceFileName() const override
        {
            return sSourceFileName;
        }

        virtual unsigned long getCodeLine() const override
        {
            return 0;
        }

        virtual std::chrono::milliseconds getTimestamp() const override
        {
            return std::chrono::milliseconds{};
        }
    };
}