#include "CallStackFrameNull.h"

namespace olg {

    static const std::string kNullName = "OLG::NULL";

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
        return 0;
    }

    unsigned long long CallStackFrameNull::getAddress() const
    {
        return 0;
    }

    static const CallStackFrameNull cfn;
}

const olg::ICallStackFrame* createCallStackFrameNull() 
{
    return &olg::cfn;
}