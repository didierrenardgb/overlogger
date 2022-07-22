#include "DynamicLibraryLinux.h"
#include "DynamicLibraryFunctionPointerLinux.h"

#include <dlfcn.h>


namespace olg::dl {

    struct DynamicLibraryLinux::DynamicLibraryLinuxImpl
    {
        DynamicLibraryLinuxImpl(void* libHandle)
            : mLibHandle{ libHandle }
        {
        }
        void* mLibHandle;
    };

    DynamicLibraryLinux::DynamicLibraryLinux(void* libHandle)
        : mImpl{ std::make_unique<DynamicLibraryLinuxImpl>(libHandle) }
    {
    }

    DynamicLibraryLinux::~DynamicLibraryLinux() = default;

    std::unique_ptr<IDynamicLibraryFunctionPointer> DynamicLibraryLinux::getFunction(const std::string& functionName) const
    {
        void* const funProcAdress = dlsym(mImpl->mLibHandle, functionName.c_str());
        if (funProcAdress == nullptr)
        {
            return nullptr;
        }
        return DynamicLibraryFunctionPointerLinux::makeUnique(funProcAdress);
    }

}
