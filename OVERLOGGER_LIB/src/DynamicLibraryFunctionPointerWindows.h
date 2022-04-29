#pragma once
#include <memory>

#include "IDynamicLibraryFunctionPointer.h"

namespace olg::dl
{
    class DynamicLibraryWindows;
    class DynamicLibraryFunctionPointerWindows : public IDynamicLibraryFunctionPointer
    {
    public:
        ~DynamicLibraryFunctionPointerWindows();
    protected:
        DynamicLibraryFunctionPointerWindows(void* funPtr);
        DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows const& other) = delete;
        DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows&& other) = delete;
        void* handle() const override;
        friend class DynamicLibraryWindows;
        class DynamicLibraryFunctionPointerWindowsImpl;
        std::unique_ptr<DynamicLibraryFunctionPointerWindowsImpl> mImpl;
    private:
        static std::unique_ptr<IDynamicLibraryFunctionPointer> makeUnique(void* funPtr);
    };

}