#include <overlogger/dll/callstack/CallStackFrameNull.h>

namespace olg
{
static const std::string kNullName = "OLG::NULL";
static const CallStackFrameNull cfn;

std::string const& CallStackFrameNull::getFunctionName() const
{
    return kNullName;
}

std::string const& CallStackFrameNull::getSourceFileName() const
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

std::string const& getNullStdString()
{
    return kNullName;
}
} // namespace olg

const olg::ICallStackFrame* getCallStackFrameNull()
{
    return &olg::cfn;
}

char const* getNullString()
{
    return olg::kNullName.c_str();
}
