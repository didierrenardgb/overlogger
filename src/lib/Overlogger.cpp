#include <mutex>

#include <overlogger/lib/Overlogger.h>
#include <overlogger/lib/callstack/CallStackLibrary.h>
#include <overlogger/lib/dll/DynamicLibraryLoaderFactory.h>
#include <overlogger/lib/dll/IDynamicLibraryLoader.h>
#include <overlogger/lib/dll/IDynamicLibrary.h>
#include <overlogger/dll/DllUtils.h>

namespace olg
{
struct Overlogger::OverloggerImpl
{
	void load()
	{
		using namespace dl;
		if (!mDynamicLibrary)
		{
			DynamicLibraryLoaderFactory factory;
			std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
			mDynamicLibrary = std::shared_ptr<IDynamicLibrary>(loader->load(kSharedLibraryName).release());
		}
	}

	std::shared_ptr<CallStackLibrary> mCallStackLibrary;
	std::shared_ptr<dl::IDynamicLibrary> mDynamicLibrary;
	std::mutex mMutex;
};

Overlogger::~Overlogger() = default;

Overlogger::Overlogger():
mImpl(std::make_unique<OverloggerImpl>())
{
}

std::shared_ptr<CallStackLibrary> Overlogger::callStackLibrary()
{
	std::lock_guard lock(mImpl->mMutex);
	if (mImpl->mCallStackLibrary)
	{
		return mImpl->mCallStackLibrary;
	}
	mImpl->load();
	return mImpl->mCallStackLibrary = CallStackLibrary::makeShared(mImpl->mDynamicLibrary);
}
} // namespace olg
