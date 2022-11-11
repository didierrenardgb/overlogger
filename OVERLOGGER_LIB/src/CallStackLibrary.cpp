#include "CallStackLibrary.h"
#include "ICallStackRetriever.h"
#include "DynamicLibraryLoaderWindows.h"
#include "DynamicLibraryFunctionCaller.h"
#include "IDynamicLibrary.h"
#include "ICallStackFrame.h"

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
	std::unique_ptr<dl::IDynamicLibraryFunctionPointer> mEqualsFrame;
	std::unique_ptr<dl::IDynamicLibraryFunctionPointer> mGetCallStackFrameNull;
	std::string_view mNullStringView;
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

	if (!mImpl->mEqualsFrame)
	{
		mImpl->mEqualsFrame = mImpl->mDynamicLibrary->getFunction("equalsFrame");
	}
	return call<bool>(mImpl->mEqualsFrame, &frame1, &frame2);
}

const ICallStackFrame& CallStackLibrary::getCallStackFrameNull()
{
	using namespace dl;
	std::lock_guard lock(mImpl->mMutex);

	if (!mImpl->mGetCallStackFrameNull)
	{
		mImpl->mGetCallStackFrameNull = mImpl->mDynamicLibrary->getFunction("getCallStackFrameNull");
	}
	return *call<const ICallStackFrame*>(mImpl->mGetCallStackFrameNull);
}

const std::string_view& CallStackLibrary::getNullString()
{
	using namespace dl;
	std::lock_guard lock(mImpl->mMutex);

	if (mImpl->mNullStringView.empty())
	{
		mImpl->mNullStringView = call<const char*>(mImpl->mDynamicLibrary->getFunction("getNullString"));
	}
	return mImpl->mNullStringView;
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
