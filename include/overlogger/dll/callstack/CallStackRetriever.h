#pragma once

#include "ICallStackRetriever.h"

#include <overlogger/dll/DllUtils.h>

namespace olg
{
class ICallStackFactory;
class CallStackRetrieverImpl; //forward declaration

class CallStackRetriever : public ICallStackRetriever
{
public:
    CallStackRetriever(std::unique_ptr<ICallStackFactory>&& callStackFactory);
    ~CallStackRetriever();

    virtual std::unique_ptr<ICallStack> retrieve() override;

private:
    std::unique_ptr<CallStackRetrieverImpl> mImpl;
};
} // namespace olg

extern "C"
{
DLLEXPORT olg::ICallStackRetriever* createCallStackRetriever();
}
