#pragma once

#include "ICallStackRetriever.h"

namespace olg
{
    class ICallStackFactory;
    class CallStackRetrieverImpl; //forward declaration

    class CallStackRetriever : public ICallStackRetriever
    {
    public:
        virtual std::unique_ptr<ICallStack> retrieve() override;
        CallStackRetriever(std::unique_ptr<ICallStackFactory>&& callStackFactory);
        ~CallStackRetriever();

    private:
        std::unique_ptr<CallStackRetrieverImpl> mImpl;
    };
}