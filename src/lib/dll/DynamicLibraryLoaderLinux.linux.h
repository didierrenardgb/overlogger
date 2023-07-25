#pragma once

#include "overlogger/lib/dll/IDynamicLibraryLoader.h"

namespace olg::dl
{
class DynamicLibraryLoaderLinux : public IDynamicLibraryLoader
{
    virtual std::unique_ptr<IDynamicLibrary> load(const std::string& path) const override;
};
} // namespace olg::dl
