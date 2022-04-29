#include "DynamicLibraryFunctionPointerWindows.h"

namespace olg::dl
{
    struct DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindowsImpl
    {
        DynamicLibraryFunctionPointerWindowsImpl(void* functionPtr) : mFunctionPointer(functionPtr) {}
        void* mFunctionPointer;
    };

    DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindows(void* funPtr) 
        : mImpl(std::make_unique<DynamicLibraryFunctionPointerWindowsImpl>(funPtr))
    { 
    }

    DynamicLibraryFunctionPointerWindows::~DynamicLibraryFunctionPointerWindows() = default;

    void* DynamicLibraryFunctionPointerWindows::handle() const
    {
        return mImpl->mFunctionPointer;
    }

    std::unique_ptr<IDynamicLibraryFunctionPointer> DynamicLibraryFunctionPointerWindows::makeUnique(void * funPtr)
    {
        return std::unique_ptr<IDynamicLibraryFunctionPointer>(new DynamicLibraryFunctionPointerWindows(funPtr));
    }


}
