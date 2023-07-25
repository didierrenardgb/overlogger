#pragma once

#include "ICallStack.h"

namespace olg
{
class CallStackNull : public ICallStack
{
public:
	virtual size_t getSize() const override;
    virtual ICallStackFrame const& getFrame(size_t index) const override;
    virtual std::vector<std::unique_ptr<ICallStackFrame>> const& getFrameList() const override;

private:
	CallStackNull();
	CallStackNull(CallStackNull const& cs) = delete;
	CallStackNull(CallStackNull&& cs) = delete;

	friend class CallStackFactory;

	//not recommendable to befriend with std::make_unique since that will allow everyone
	//to create CallStackNull instances using that function. Instead, we define our own
	//creation function for make_unique, that will only be available to our friend classes

	static std::unique_ptr<ICallStack> makeUnique();
};
} // namespace olg
