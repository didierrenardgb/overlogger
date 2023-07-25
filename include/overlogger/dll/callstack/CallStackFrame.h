#pragma once

#include <string>
#include <memory>

#include "ICallStackFrame.h"

namespace olg
{
class CallStackFrame : public ICallStackFrame
{
public:
	CallStackFrame(unsigned long long address, std::string const& functionName,
		std::string const& sourceFileName,
		unsigned long codeLine);
	~CallStackFrame();	//Here we declare the destructor because otherwise the forward declaration of CallStackFrameImpl would be incomplete 
						//and the compiler based implementation of the ~CallStackFrame wouldn't know how to destruct mImpl

	virtual std::string const& getFunctionName() const override;
	virtual std::string const& getSourceFileName() const override;
	virtual unsigned long getCodeLine() const override;
    virtual unsigned long long getAddress() const override;

private:
	struct CallStackFrameImpl;	//Forward declaration of implementation. We use struct because all members will be public so nOpt
	std::unique_ptr<CallStackFrameImpl> mImpl;
};
} // namespace olg
