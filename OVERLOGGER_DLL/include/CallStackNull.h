#pragma once

#include <vector>
#include "ICallStack.h"
#include "CallStackFrameNull.h"

namespace olg
{
    class CallStackNull : public ICallStack
    {
    private:
        inline static const CallStackFrameNull sNullCallStackFrame;
        static const std::vector<std::unique_ptr<ICallStackFrame>> sNullFrameList;
        CallStackNull() = default;
        CallStackNull(const CallStackNull &cs) = delete;
        CallStackNull(CallStackNull &&cs) = delete;

        friend class CallStackFactory;

    public:
        virtual size_t getSize() const override { return 0u; };
        virtual const ICallStackFrame &getFrame(size_t index) const override { return sNullCallStackFrame; };
        virtual const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const override { return sNullFrameList; };
    };
}