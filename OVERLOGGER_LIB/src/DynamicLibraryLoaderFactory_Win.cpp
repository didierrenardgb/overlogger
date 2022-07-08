#include "DynamicLibraryLoaderFactory.h"
#include "DynamicLibraryLoaderWindows.h"

namespace olg::dl
{
	std::unique_ptr<IDynamicLibraryLoader> DynamicLibraryLoaderFactory::create() const
	{
		return std::make_unique<DynamicLibraryLoaderWindows>();
	}
}
