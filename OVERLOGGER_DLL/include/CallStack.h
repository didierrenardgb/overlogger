#pragma once

#include <vector>

#include "ICallStack.h"

namespace olg
{
    class CallStack : public ICallStack
    {
    private:
        class CallStackImpl; // forward declaration

        std::unique_ptr<CallStackImpl> mCallStackImpl;
        CallStack(std::vector<std::unique_ptr<ICallStackFrame>>&& frames);
        CallStack(const CallStack& cs) = delete;
        CallStack(CallStack&& cs) = delete;
        ~CallStack();

        friend class CallStackFactory;

        static std::unique_ptr<ICallStack> makeUnique(std::vector<std::unique_ptr<ICallStackFrame>>&&);

    public:
        virtual size_t getSize() const override;
        virtual const ICallStackFrame& getFrame(size_t index) const override;
        virtual const std::vector<std::unique_ptr<ICallStackFrame>>& getFrameList() const override;
    };
}
