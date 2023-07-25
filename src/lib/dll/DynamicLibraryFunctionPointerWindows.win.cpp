#include "DynamicLibraryFunctionPointerWindows.win.h"

namespace olg::dl
{
struct DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindowsImpl
{
    DynamicLibraryFunctionPointerWindowsImpl(DynamicLibrarySymbolHandler functionPtr) : mFunctionPointer(functionPtr) {}
    DynamicLibrarySymbolHandler mFunctionPointer;
};

DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindows(DynamicLibrarySymbolHandler funPtr)
    : mImpl(std::make_unique<DynamicLibraryFunctionPointerWindowsImpl>(funPtr))
{ 
}

DynamicLibraryFunctionPointerWindows::~DynamicLibraryFunctionPointerWindows() = default;

DynamicLibrarySymbolHandler DynamicLibraryFunctionPointerWindows::handle() const
{
    return mImpl->mFunctionPointer;
}

std::unique_ptr<IDynamicLibraryFunctionPointer> DynamicLibraryFunctionPointerWindows::makeUnique(DynamicLibrarySymbolHandler funPtr)
{
    return std::unique_ptr<IDynamicLibraryFunctionPointer>(new DynamicLibraryFunctionPointerWindows(funPtr));
}
} // namespace olg::dl
