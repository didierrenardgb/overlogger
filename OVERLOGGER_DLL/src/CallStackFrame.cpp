#include "CallStackFrame.h"

namespace olg {
	//Keeping imp public cause only is accesible from CallStackFrame, reason why it's a struct, not a class
	struct CallStackFrame::CallStackFrameImpl {

		CallStackFrameImpl(const std::string& functionName, const std::string& sourceFileName,
			unsigned long codeLine) : mFunctionName(functionName), mSourceFileName(sourceFileName), mCodeLine(codeLine) {}

		std::string mFunctionName;
		std::string mSourceFileName;
		unsigned long mCodeLine = 0L;
		std::chrono::milliseconds mTimestamp;

	};

	//uOpt: We are not using aggregate initialization on the impl because that would create an object that would be copied constructor afterwards
	CallStackFrame::CallStackFrame(const std::string& functionName, const std::string& sourceFileName,
		unsigned long codeLine) :mImpl(std::make_unique<CallStackFrameImpl>(functionName, sourceFileName, codeLine)) {

	}

	CallStackFrame::~CallStackFrame() = default;


	const std::string& CallStackFrame::getFunctionName() const { return mImpl->mFunctionName; }	//Virtual and override don't get on the imp
	const std::string& CallStackFrame::getSourceFileName() const { return mImpl->mSourceFileName; }
	unsigned long CallStackFrame::getCodeLine() const { return mImpl->mCodeLine; }
	std::chrono::milliseconds CallStackFrame::getTimestamp() const { return mImpl->mTimestamp; }

}

