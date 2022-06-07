#include "IDynamicLibraryFunctionCaller.h"
#include "IDynamicLibraryFunctionPointer.h"

namespace olg::dl
{
	void* IDynamicLibraryFunctionCaller::handle(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer) const
	{
		return functionPointer->handle();
	}
}
