#include "DynamicLibraryLoaderWindows.h"
#include "DynamicLibraryWindows.h"
#include <libloaderapi.h>

namespace olg::dl
{

    std::unique_ptr<IDynamicLibrary> DynamicLibraryLoaderWindows::load(const std::string & path) const
    {
        const HMODULE library = LoadLibrary((path + ".dll").c_str());
        return std::make_unique<DynamicLibraryWindows>(library);
    }

}
