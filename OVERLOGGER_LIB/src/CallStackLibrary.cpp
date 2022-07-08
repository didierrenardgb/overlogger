#include "CallStackLibrary.h"
#include "ICallStackRetriever.h"
#include "DynamicLibraryLoaderWindows.h"
#include "DynamicLibraryFunctionCaller.h"
#include "IDynamicLibrary.h"

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
};

std::unique_ptr<ICallStackRetriever> CallStackLibrary::createCallStackRetriever()
{
	using namespace dl;
	if (!mImpl->mCreateCallStackRetriever)
	{
		mImpl->mCreateCallStackRetriever = mImpl->mDynamicLibrary->getFunction("createCallStackRetriever");
	}
	return call<ICallStackRetriever*>(mImpl->mCreateCallStackRetriever);
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
	// TODO: testear que se llame al destructor
	return std::make_shared<MakeSharedEnabled>(dynamicLibrary);
}
}
