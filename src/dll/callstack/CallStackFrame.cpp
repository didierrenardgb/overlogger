#include <overlogger/dll/callstack/CallStackFrame.h>

namespace olg
{
//Keeping imp public cause only is accesible from CallStackFrame, reason why it's a struct, not a class
struct CallStackFrame::CallStackFrameImpl
{
	CallStackFrameImpl(unsigned long long address, std::string const& functionName,
		std::string const& sourceFileName,
        unsigned long codeLine):
	mAddress{address},
	mFunctionName(functionName),
	mSourceFileName(sourceFileName),
	mCodeLine(codeLine)
	{
	}

	std::string mFunctionName;
	std::string mSourceFileName;
	unsigned long mCodeLine = 0L;
    unsigned long long mAddress = 0L;
};

//uOpt: We are not using aggregate initialization on the impl because that would create an object that would be copied constructor afterwards
CallStackFrame::CallStackFrame(unsigned long long address, std::string const& functionName,
	std::string const& sourceFileName,
	unsigned long codeLine):
mImpl(std::make_unique<CallStackFrameImpl>(address, functionName, sourceFileName, codeLine))
{
}

CallStackFrame::~CallStackFrame() = default;

std::string const& CallStackFrame::getFunctionName() const //Virtual and override don't go on the imp
{
	return mImpl->mFunctionName;
}

std::string const& CallStackFrame::getSourceFileName() const
{
	return mImpl->mSourceFileName;
}

unsigned long CallStackFrame::getCodeLine() const
{
	return mImpl->mCodeLine;
}

unsigned long long CallStackFrame::getAddress() const
{
	return mImpl->mAddress;
}

} // namespace olg
