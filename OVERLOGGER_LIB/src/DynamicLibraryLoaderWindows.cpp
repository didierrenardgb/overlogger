#include "DynamicLibraryLoaderWindows.h"
#include "DynamicLibraryWindows.h"
#include <libloaderapi.h>

namespace olg::dl
{

    std::unique_ptr<IDynamicLibrary> DynamicLibraryLoaderWindows::load(const std::string & path) const
    {
        const HMODULE library = LoadLibrary(path.c_str());
        return std::unique_ptr<IDynamicLibrary>(new DynamicLibraryWindows(library));
    }

}