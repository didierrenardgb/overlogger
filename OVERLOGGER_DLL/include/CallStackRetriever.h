#pragma once

#include "ICallStackRetriever.h"

namespace olg
{
    class CallStackRetriever : public ICallStackRetriever
    {
    public:
        virtual std::unique_ptr<ICallStack> retrieve() override;
        CallStackRetriever(std::unique_ptr<ICallStackFactory>&& callStackFactory);
        ~CallStackRetriever();

    private:
        HANDLE mProcessHandle;
        std::unique_ptr<ICallStackFactory> mCallStackFactory;
    };
}