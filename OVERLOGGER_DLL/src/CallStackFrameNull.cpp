#include "CallStackFrameNull.h"

namespace olg
{
    static const std::string kNullName = "OLG::NULL";
    static const CallStackFrameNull cfn;

    const std::string& CallStackFrameNull::getFunctionName() const
    {
        return kNullName;
    }

    const std::string& CallStackFrameNull::getSourceFileName() const
    {
        return kNullName;
    }

    unsigned long CallStackFrameNull::getCodeLine() const
    {
        return 0ul;
    }

    unsigned long long CallStackFrameNull::getAddress() const
    {
        return 0ull;
    }

    const std::string& getNullStdString()
    {
        return kNullName;
    }
}

const olg::ICallStackFrame* getCallStackFrameNull()
{
    return &olg::cfn;
}

const char* getNullString()
{
    return olg::kNullName.c_str();
}