#include "Overlogger.h"
#include "CallStackLibrary.h"
#include "DynamicLibraryLoaderFactory.h"
#include "IDynamicLibraryLoader.h"
#include "IDynamicLibrary.h"

#include <mutex>

namespace olg
{
	struct Overlogger::OverloggerImpl
	{
		std::shared_ptr<CallStackLibrary> mCallStackLibrary;
		std::shared_ptr<dl::IDynamicLibrary> mDynamicLibrary;
		std::mutex mMutex;

		void load()
		{
			using namespace dl;
			if (!mDynamicLibrary)
			{
				DynamicLibraryLoaderFactory factory;
				std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
				mDynamicLibrary = std::shared_ptr<IDynamicLibrary>(loader->load("OVERLOGGER_DLL").release());
			}
		}
	};

	Overlogger::~Overlogger() = default;

	Overlogger::Overlogger() : mImpl(std::make_unique<OverloggerImpl>()) {}

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
}
