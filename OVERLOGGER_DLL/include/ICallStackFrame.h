#pragma once

#include <string>

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
