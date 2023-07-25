#pragma once

#include <vector>

#include "ICallStack.h"

namespace olg
{
class CallStack : public ICallStack
{
public:
    virtual size_t getSize() const override;
    virtual ICallStackFrame const& getFrame(size_t index) const override;
    virtual std::vector<std::unique_ptr<ICallStackFrame>> const& getFrameList() const override;

private:
    CallStack(std::vector<std::unique_ptr<ICallStackFrame>>&& frames);
    CallStack(const CallStack& cs) = delete;
    CallStack(CallStack&& cs) = delete;
    ~CallStack();

    friend class CallStackFactory;

    static std::unique_ptr<ICallStack> makeUnique(std::vector<std::unique_ptr<ICallStackFrame>>&&);

    class CallStackImpl; // forward declaration
    std::unique_ptr<CallStackImpl> mCallStackImpl;
};
} // namespace olg
