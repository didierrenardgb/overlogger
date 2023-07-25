#include "DynamicLibraryFunctionPointerLinux.h"

namespace olg::dl
{
    // TODO: void* en win y linux

    struct DynamicLibraryFunctionPointerLinux::DynamicLibraryFunctionPointerLinuxImpl
    {
        DynamicLibraryFunctionPointerLinuxImpl(DynamicLibrarySymbolHandlr functionPtr) : mFunctionPointer(functionPtr) {}
        DynamicLibrarySymbolHandlr mFunctionPointer;
    };

    DynamicLibraryFunctionPointerLinux::DynamicLibraryFunctionPointerLinux(DynamicLibrarySymbolHandlr funPtr)
        : mImpl(std::make_unique<DynamicLibraryFunctionPointerLinuxImpl>(funPtr))
    {
    }

    DynamicLibraryFunctionPointerLinux::~DynamicLibraryFunctionPointerLinux() = default;

    DynamicLibrarySymbolHandlr DynamicLibraryFunctionPointerLinux::handle() const
    {
        return mImpl->mFunctionPointer;
    }

    std::unique_ptr<IDynamicLibraryFunctionPointer> DynamicLibraryFunctionPointerLinux::makeUnique(DynamicLibrarySymbolHandlr funPtr)
    {
        return std::unique_ptr<IDynamicLibraryFunctionPointer>(new DynamicLibraryFunctionPointerLinux(funPtr));
    }


}
