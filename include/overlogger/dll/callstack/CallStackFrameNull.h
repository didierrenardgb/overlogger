#pragma once

#include <string>

#include "ICallStackFrame.h"

#include <overlogger/dll/DllUtils.h>

namespace olg
{
class CallStackFrameNull : public ICallStackFrame
{
public:
    virtual std::string const& getFunctionName() const override;
    virtual std::string const& getSourceFileName() const override;
    virtual unsigned long getCodeLine() const override;
    virtual unsigned long long getAddress() const override;
};

const std::string& getNullStdString();
} // namespace olg

extern "C"
{
DLLEXPORT const olg::ICallStackFrame* getCallStackFrameNull();
DLLEXPORT char const* getNullString();
}
