#include "CallStackFrameNull.h"

namespace olg {
    const std::string& CallStackFrameNull::getFunctionName() const
    {
        static const std::string sFunctionName = "?NULL";
        return sFunctionName;
    }

    const std::string& CallStackFrameNull::getSourceFileName() const
    {
        static const std::string sSourceFileName = "?NULL";
        return sSourceFileName;
    }

    unsigned long CallStackFrameNull::getCodeLine() const
    {
        return 0;
    }

    unsigned long long CallStackFrameNull::getAddress() const
    {
        return 0;
    }
}
