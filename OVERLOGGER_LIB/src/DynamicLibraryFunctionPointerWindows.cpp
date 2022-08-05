#include "DynamicLibraryFunctionPointerWindows.h"

namespace olg::dl
{
    struct DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindowsImpl
    {
        DynamicLibraryFunctionPointerWindowsImpl(DynamicLibrarySymbolHandlr functionPtr) : mFunctionPointer(functionPtr) {}
        DynamicLibrarySymbolHandlr mFunctionPointer;
    };

    DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindows(DynamicLibrarySymbolHandlr funPtr) 
        : mImpl(std::make_unique<DynamicLibraryFunctionPointerWindowsImpl>(funPtr))
    { 
    }

    DynamicLibraryFunctionPointerWindows::~DynamicLibraryFunctionPointerWindows() = default;

    DynamicLibrarySymbolHandlr DynamicLibraryFunctionPointerWindows::handle() const
    {
        return mImpl->mFunctionPointer;
    }

    std::unique_ptr<IDynamicLibraryFunctionPointer> DynamicLibraryFunctionPointerWindows::makeUnique(DynamicLibrarySymbolHandlr funPtr)
    {
        return std::unique_ptr<IDynamicLibraryFunctionPointer>(new DynamicLibraryFunctionPointerWindows(funPtr));
    }


}
