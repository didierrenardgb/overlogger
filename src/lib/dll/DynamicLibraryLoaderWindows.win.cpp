#include <Windows.h> // Required to be included before libloaderapi
#include <libloaderapi.h>

#include "DynamicLibraryLoaderWindows.win.h"
#include "DynamicLibraryWindows.win.h"

namespace olg::dl
{

std::unique_ptr<IDynamicLibrary> DynamicLibraryLoaderWindows::load(std::string const& path) const
{
    HMODULE const library = LoadLibrary((path + ".dll").c_str());
    if (library != NULL)
    {
        return std::make_unique<DynamicLibraryWindows>(library);
    }
    return nullptr;
}

} // namespace olg::dl
