#pragma once
#include <memory>

#include "IDynamicLibraryFunctionPointer.h"

namespace olg::dl
{
    class DynamicLibraryLinux;
    class DynamicLibraryFunctionPointerLinux : public IDynamicLibraryFunctionPointer
    {
    public:
        ~DynamicLibraryFunctionPointerLinux();
    protected:
        DynamicLibraryFunctionPointerLinux(void* funPtr);
        DynamicLibraryFunctionPointerLinux(DynamicLibraryFunctionPointerLinux const& other) = delete;
        DynamicLibraryFunctionPointerLinux(DynamicLibraryFunctionPointerLinux&& other) = delete;
        void* handle() const override;
        friend class DynamicLibraryLinux;
        class DynamicLibraryFunctionPointerLinuxImpl;
        std::unique_ptr<DynamicLibraryFunctionPointerLinuxImpl> mImpl;
    private:
        static std::unique_ptr<IDynamicLibraryFunctionPointer> makeUnique(void* funPtr);
    };

}