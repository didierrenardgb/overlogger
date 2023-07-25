#pragma once

#include <memory>
#include <string>

namespace olg::dl
{
class IDynamicLibraryFunctionPointer;

class IDynamicLibrary
{
public:
    virtual std::unique_ptr<IDynamicLibraryFunctionPointer> getFunction(std::string const& functionName) const = 0;
};
} // namespace olg::dl
