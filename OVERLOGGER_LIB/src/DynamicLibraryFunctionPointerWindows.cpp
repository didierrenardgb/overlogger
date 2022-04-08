
#include "DynamicLibraryFunctionPointerWindows.h"

DynamicLibraryFunctionPointerWindows::~DynamicLibraryFunctionPointerWindows() = default;

struct DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindowsImpl
{
	DynamicLibraryFunctionPointerWindowsImpl(void* functionPtr) : mFunctionPointer(functionPtr) {}
    void* mFunctionPointer;
};

void* DynamicLibraryFunctionPointerWindows::handle() const
{
    return mImpl->mFunctionPointer;
}

DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindows(void* handle) :
	mImpl(std::make_unique<DynamicLibraryFunctionPointerWindowsImpl>(handle)) { }