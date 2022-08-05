#pragma once
#include <memory>

#include "IDynamicLibraryFunctionPointer.h"

namespace olg::dl
{
    typedef void* DynamicLibrarySymbolHandlr;
    class DynamicLibraryWindows;
    class DynamicLibraryFunctionPointerWindows : public IDynamicLibraryFunctionPointer
    {
    public:
        ~DynamicLibraryFunctionPointerWindows();
    protected:
        DynamicLibraryFunctionPointerWindows(DynamicLibrarySymbolHandlr funPtr);
        DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows const& other) = delete;
        DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows&& other) = delete;
        DynamicLibrarySymbolHandlr handle() const override;
        friend class DynamicLibraryWindows;
        class DynamicLibraryFunctionPointerWindowsImpl;
        std::unique_ptr<DynamicLibraryFunctionPointerWindowsImpl> mImpl;
    private:
        static std::unique_ptr<IDynamicLibraryFunctionPointer> makeUnique(DynamicLibrarySymbolHandlr funPtr);
    };

}