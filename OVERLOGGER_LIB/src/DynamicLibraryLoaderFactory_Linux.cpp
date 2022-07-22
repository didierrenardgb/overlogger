#include "DynamicLibraryLoaderFactory.h"
#include "DynamicLibraryLoaderLinux.h"

namespace olg::dl
{
	std::unique_ptr<IDynamicLibraryLoader> DynamicLibraryLoaderFactory::create() const
	{
		return std::make_unique<DynamicLibraryLoaderLinux>();
	}
}
