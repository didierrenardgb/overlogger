#pragma once

#include "IDynamicLibrary.h"
#include <Windows.h>

namespace olg::dl
{
    class DynamicLibraryWindows : public IDynamicLibrary
    {
    public:
        DynamicLibraryWindows(HMODULE libHandle);
        ~DynamicLibraryWindows();
        virtual std::unique_ptr<IDynamicLibraryFunctionPointer> getFunction(const std::string &functionName) const override;      
    private:
        class DynamicLibraryWindowsImpl;
        std::unique_ptr<DynamicLibraryWindowsImpl> mImpl;
    };

}