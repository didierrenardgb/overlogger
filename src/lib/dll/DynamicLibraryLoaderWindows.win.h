#pragma once

#include <overlogger/lib/dll/IDynamicLibraryLoader.h>

namespace olg::dl
{
class DynamicLibraryLoaderWindows : public IDynamicLibraryLoader
{
    virtual std::unique_ptr<IDynamicLibrary> load(std::string const& path) const override;
};
} // namespace olg::dl
