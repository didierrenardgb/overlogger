#pragma once
#include <string>
#include "ICallStackFrame.h"

namespace olg
{
    class CallStackFrame : public ICallStackFrame
    {
    private:
        std::string mFunctionName;
        std::string mSourceFileName;
        unsigned long mCodeLine;
        std::chrono::milliseconds mTimestamp;

    public:
        CallStackFrame(const std::string &functionName, const std::string &sourceFileName,
                       unsigned long codeLine)
            : mFunctionName{functionName}, mSourceFileName{sourceFileName}, mCodeLine{codeLine}
        {
        }

        virtual const std::string &getFunctionName() const override
        {
            return mFunctionName;
        }

        virtual const std::string &getSourceFileName() const override
        {
            return mSourceFileName;
        }

        virtual unsigned long getCodeLine() const override
        {
            return mCodeLine;
        }

        virtual std::chrono::milliseconds getTimestamp() const override
        {
            return mTimestamp;
        }
    };
}