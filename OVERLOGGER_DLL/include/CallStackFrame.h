#pragma once

#include <string>
#include <memory>

#include "ICallStackFrame.h"

namespace olg
{
    class CallStackFrame : public ICallStackFrame
    {
    private:
		struct CallStackFrameImpl;	//Forward declaration of implementation. We use struct because all members will be public so nOpt
		std::unique_ptr<CallStackFrameImpl> mImpl;

    public:
		CallStackFrame(unsigned long long address, const std::string &functionName, const std::string &sourceFileName,
			unsigned long codeLine);
		~CallStackFrame();	//Here we declare the destructor because otherwise the forward declaration of CallStackFrameImpl would be incomplete 
							//and the compiler based implementation of the ~CallStackFrame wouldn't know how to destruct mImpl

		virtual const std::string &getFunctionName() const override;
		virtual const std::string &getSourceFileName() const override;
		virtual unsigned long getCodeLine() const override;
        virtual unsigned long long getAddress() const override;
    };
}
