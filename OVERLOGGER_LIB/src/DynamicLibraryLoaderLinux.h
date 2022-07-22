#pragma once

#include "IDynamicLibraryLoader.h"

namespace olg::dl {
    class DynamicLibraryLoaderLinux : public IDynamicLibraryLoader
    {
        virtual std::unique_ptr<IDynamicLibrary> load(const std::string& path) const override;
    };
}