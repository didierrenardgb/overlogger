#pragma once

#include "ICallStack.h"

namespace olg
{
    class CallStackNull : public ICallStack
    {
    private:
        CallStackNull() = default;
        CallStackNull(const CallStackNull &cs) = delete;
        CallStackNull(CallStackNull &&cs) = delete;

        friend std::unique_ptr<CallStackNull> std::make_unique<CallStackNull>();

    public:
        virtual size_t getSize() const override { return 0u; };
        virtual const ICallStackFrame &getFrame(size_t index) const override;
        virtual const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const override;
    };
}