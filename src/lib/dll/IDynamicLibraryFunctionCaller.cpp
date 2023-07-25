#include <overlogger/lib/dll/IDynamicLibraryFunctionCaller.h>
#include <overlogger/lib/dll/IDynamicLibraryFunctionPointer.h>

namespace olg::dl
{
void* IDynamicLibraryFunctionCaller::handle(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer) const
{
	return functionPointer->handle();
}
} // namespace olg::dl
