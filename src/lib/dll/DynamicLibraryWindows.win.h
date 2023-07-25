#pragma once

#include <Windows.h>

#include <overlogger/lib/dll/IDynamicLibrary.h>

namespace olg::dl
{
class DynamicLibraryWindows : public IDynamicLibrary
{
public:
    DynamicLibraryWindows(HMODULE libHandle);
    ~DynamicLibraryWindows();

    virtual std::unique_ptr<IDynamicLibraryFunctionPointer> getFunction(std::string const& functionName) const override;

private:
    class DynamicLibraryWindowsImpl;
    std::unique_ptr<DynamicLibraryWindowsImpl> mImpl;
};
} // namespace olg::dl
