#pragma once

namespace olg::dl
{
class IDynamicLibraryFunctionPointer
{
public:
    virtual ~IDynamicLibraryFunctionPointer() = default;

protected:
    friend class IDynamicLibraryFunctionCaller;
    virtual void* handle() const = 0;
};
} // namespace olg::dl
