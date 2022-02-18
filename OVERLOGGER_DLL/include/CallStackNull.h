#pragma once

#include "ICallStack.h"

namespace olg
{
    class CallStackNull : public ICallStack
    {
    private:
		CallStackNull();
        CallStackNull(const CallStackNull &cs) = delete;
        CallStackNull(CallStackNull &&cs) = delete;

		friend class CallStackFactory;

		//not recommendable to befriend with std::make_unique since that will allow everyone
		//to create CallStackNull instances using that function. Instead, we define our own
		//creation function for make_unique, that will only be available to our friend classes

		static std::unique_ptr<ICallStack> makeUnique();

    public:
		virtual size_t getSize() const override;
        virtual const ICallStackFrame &getFrame(size_t index) const override;
        virtual const std::vector<std::unique_ptr<ICallStackFrame>> &getFrameList() const override;
    };
}
