#pragma once

#include "IDynamicLibrary.h"

namespace olg::dl
{
    class DynamicLibraryLinux : public IDynamicLibrary
    {
    public:
        DynamicLibraryLinux(void* libHandle);
        ~DynamicLibraryLinux();
        virtual std::unique_ptr<IDynamicLibraryFunctionPointer> getFunction(const std::string& functionName) const override;
    private:
        class DynamicLibraryLinuxImpl;
        std::unique_ptr<DynamicLibraryLinuxImpl> mImpl;
    };

}