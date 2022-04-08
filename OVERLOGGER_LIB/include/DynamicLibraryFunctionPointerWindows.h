#pragma once
#include <memory>

#include "IDynamicLibraryFunctionPointer.h"

class DynamicLibraryFunctionPointerWindows : public IDynamicLibraryFunctionPointer
{
	~DynamicLibraryFunctionPointerWindows();
    protected:
        DynamicLibraryFunctionPointerWindows(void*);
        DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows const& other) = delete;
        DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows&& other) = delete;
        void* handle() const override;
        friend class DynamicLibraryWindows;
        class DynamicLibraryFunctionPointerWindowsImpl;
        std::unique_ptr<DynamicLibraryFunctionPointerWindowsImpl> mImpl;
};