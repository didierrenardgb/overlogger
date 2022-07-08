#include "Overlogger.h"
#include "CallStackLibrary.h"
#include "DynamicLibraryLoaderFactory.h"
#include "IDynamicLibraryLoader.h"
#include "IDynamicLibrary.h"

namespace olg
{
	struct Overlogger::OverloggerImpl
	{
		std::shared_ptr<CallStackLibrary> mCallStackLibrary;
		std::shared_ptr<dl::IDynamicLibrary> mDynamicLibrary;
		void load()
		{
			using namespace dl;
			if (!mDynamicLibrary)
			{
				DynamicLibraryLoaderFactory factory;
				std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
				mDynamicLibrary = std::shared_ptr<IDynamicLibrary>(loader->load("overlogger_dll").release());
			}
		}
	};

	Overlogger::~Overlogger() = default;

	Overlogger::Overlogger() : mImpl(std::make_unique<OverloggerImpl>()) {}

	std::shared_ptr<CallStackLibrary> Overlogger::callStackLibrary()
	{
		if (mImpl->mCallStackLibrary)
		{
			return mImpl->mCallStackLibrary;
		}
		mImpl->load();
		return mImpl->mCallStackLibrary = CallStackLibrary::makeShared(mImpl->mDynamicLibrary);
	}
}
