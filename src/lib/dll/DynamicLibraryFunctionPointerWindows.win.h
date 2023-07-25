#pragma once

#include <memory>

#include <overlogger/lib/dll/IDynamicLibraryFunctionPointer.h>

namespace olg::dl
{
typedef void* DynamicLibrarySymbolHandler;
class DynamicLibraryWindows;

class DynamicLibraryFunctionPointerWindows : public IDynamicLibraryFunctionPointer
{
public:
    ~DynamicLibraryFunctionPointerWindows();

protected:
    DynamicLibraryFunctionPointerWindows(DynamicLibrarySymbolHandler funPtr);
    DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows const& other) = delete;
    DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows&& other) = delete;

    DynamicLibrarySymbolHandler handle() const override;

    friend class DynamicLibraryWindows;
    class DynamicLibraryFunctionPointerWindowsImpl;
    std::unique_ptr<DynamicLibraryFunctionPointerWindowsImpl> mImpl;

private:
    static std::unique_ptr<IDynamicLibraryFunctionPointer> makeUnique(DynamicLibrarySymbolHandler funPtr);
};
} // namespace olg::dl
