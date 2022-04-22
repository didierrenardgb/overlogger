#pragma once

#include "IDynamicLibraryLoader.h"

namespace olg::dl {

    class DynamicLibraryLoaderWindows : IDynamicLibraryLoader {
    public:
        virtual std::unique_ptr<IDynamicLibrary> load(const std::string &path) = 0;
    };
}

//HINSTANCE hGetProcIDDLL = LoadLibrary();