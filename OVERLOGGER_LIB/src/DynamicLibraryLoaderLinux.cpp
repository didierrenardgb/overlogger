#include "DynamicLibraryLoaderLinux.h"
#include "DynamicLibraryLinux.h"

#include <dlfcn.h>
#include <iostream>

namespace olg::dl
{

    std::unique_ptr<IDynamicLibrary> DynamicLibraryLoaderLinux::load(const std::string& path) const
    {
        void* library = dlopen((std::string{ "./lib" } + path + ".so").c_str(), RTLD_LAZY);
        return std::unique_ptr<IDynamicLibrary>(new DynamicLibraryLinux(library));
    }

}
