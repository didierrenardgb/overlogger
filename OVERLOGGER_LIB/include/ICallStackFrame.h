#pragma once
#include <string>
#include <chrono>

class ICallStackFrame
{
public:
    virtual const std::string &getFunctionName() const = 0;
    virtual const std::string &getSourceFileName() const = 0;
    virtual unsigned long getCodeLine() const = 0;
    virtual std::chrono::milliseconds getTimestamp() const = 0;
};