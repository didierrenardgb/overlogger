#include "CallStackLibrary.h"
#include "ICallStackRetriever.h"
#include "DynamicLibraryLoaderWindows.h"
#include "DynamicLibraryFunctionCaller.h"
#include "IDynamicLibrary.h"

#include <mutex>

namespace olg 
{

struct CallStackLibrary::MakeSharedEnabled : public CallStackLibrary
{
	MakeSharedEnabled(std::shared_ptr<dl::IDynamicLibrary> const& dynamicLibrary) : CallStackLibrary(dynamicLibrary) {}
};

struct CallStackLibrary::CallStackLibraryImpl
{
	std::shared_ptr<dl::IDynamicLibrary> mDynamicLibrary;
	std::unique_ptr<dl::IDynamicLibraryFunctionPointer> mCreateCallStackRetriever;
	std::unique_ptr<dl::IDynamicLibraryFunctionPointer> mEqualFrame;
	std::mutex mMutex;
};

std::unique_ptr<ICallStackRetriever> CallStackLibrary::createCallStackRetriever()
{
	using namespace dl;
	std::lock_guard lock(mImpl->mMutex);

	if (!mImpl->mCreateCallStackRetriever)
	{
		mImpl->mCreateCallStackRetriever = mImpl->mDynamicLibrary->getFunction("createCallStackRetriever");
	}
	return call<ICallStackRetriever*>(mImpl->mCreateCallStackRetriever);
}

bool CallStackLibrary::equals(ICallStackFrame const& frame1, ICallStackFrame const& frame2)
{
	using namespace dl;
	std::lock_guard lock(mImpl->mMutex);

	if (!mImpl->mEqualFrame)
	{
		mImpl->mEqualFrame = mImpl->mDynamicLibrary->getFunction("equalsFrame");
	}
	return call<bool>(mImpl->mEqualFrame, &frame1, &frame2);
}

CallStackLibrary::CallStackLibrary(std::shared_ptr<dl::IDynamicLibrary> const& dynamicLibrary)
	:
	mImpl(std::make_unique<CallStackLibraryImpl>())
{
	mImpl->mDynamicLibrary = dynamicLibrary;
}

CallStackLibrary::~CallStackLibrary() = default;

std::shared_ptr<CallStackLibrary> CallStackLibrary::makeShared(std::shared_ptr<dl::IDynamicLibrary> const& dynamicLibrary)
{
	return std::make_shared<MakeSharedEnabled>(dynamicLibrary);
}
}
