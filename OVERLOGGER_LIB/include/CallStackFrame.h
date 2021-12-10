#pragma once
#include <string>
#include <chrono>

class CallStackFrame
{
private:
    std::string mFunctionName;
    std::string mSourceFileName;
    unsigned long mCodeLine;
    std::chrono::milliseconds mTimestamp;

public:
    CallStackFrame(const std::string &functionName, const std::string &sourceFileName,
                   unsigned long codeLine, std::chrono::milliseconds timestamp)
        : mFunctionName{functionName}, mSourceFileName{sourceFileName}, mCodeLine{codeLine}, mTimestamp{timestamp}
    {
    }

    const std::string &getFunctionName() const
    {
        return mFunctionName;
    }

    const std::string &getSourceFileName() const
    {
        return mSourceFileName;
    }

    unsigned long getCodeLine() const
    {
        return mCodeLine;
    }

    std::chrono::milliseconds getTimestamp() const
    {
        return mTimestamp;
    }

};