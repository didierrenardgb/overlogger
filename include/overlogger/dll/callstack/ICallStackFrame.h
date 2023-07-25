#pragma once

#include <string>
#include <stdbool.h>

#include <overlogger/dll/DllUtils.h>

namespace olg
{
class ICallStackFrame
{
public:
	virtual ~ICallStackFrame();

    virtual std::string const& getFunctionName() const = 0;
    virtual std::string const& getSourceFileName() const = 0;
    virtual unsigned long getCodeLine() const = 0;
    virtual unsigned long long getAddress() const = 0;
};
} // namespace olg

extern "C"
{
DLLEXPORT bool equalsFrame(olg::ICallStackFrame const* cs1, olg::ICallStackFrame const* cs2);
}
