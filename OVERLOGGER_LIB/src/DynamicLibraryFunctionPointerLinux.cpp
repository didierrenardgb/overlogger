#include "DynamicLibraryFunctionPointerLinux.h"

namespace olg::dl
{
    // TODO: void* en win y linux

    struct DynamicLibraryFunctionPointerLinux::DynamicLibraryFunctionPointerLinuxImpl
    {
        DynamicLibraryFunctionPointerLinuxImpl(void* functionPtr) : mFunctionPointer(functionPtr) {}
        void* mFunctionPointer;
    };

    DynamicLibraryFunctionPointerLinux::DynamicLibraryFunctionPointerLinux(void* funPtr)
        : mImpl(std::make_unique<DynamicLibraryFunctionPointerLinuxImpl>(funPtr))
    {
    }

    DynamicLibraryFunctionPointerLinux::~DynamicLibraryFunctionPointerLinux() = default;

    void* DynamicLibraryFunctionPointerLinux::handle() const
    {
        return mImpl->mFunctionPointer;
    }

    std::unique_ptr<IDynamicLibraryFunctionPointer> DynamicLibraryFunctionPointerLinux::makeUnique(void* funPtr)
    {
        return std::unique_ptr<IDynamicLibraryFunctionPointer>(new DynamicLibraryFunctionPointerLinux(funPtr));
    }


}
