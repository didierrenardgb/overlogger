#include "DynamicLibraryLoaderWindows.win.h"

#include <overlogger/lib/dll/DynamicLibraryLoaderFactory.h>

namespace olg::dl
{
std::unique_ptr<IDynamicLibraryLoader> DynamicLibraryLoaderFactory::create() const
{
	return std::make_unique<DynamicLibraryLoaderWindows>();
}
} // namespace olg::dl
