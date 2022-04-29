#include "DynamicLibraryWindows.h"
#include "DynamicLibraryFunctionPointerWindows.h"

namespace olg::dl {

    struct DynamicLibraryWindows::DynamicLibraryWindowsImpl 
    {
        DynamicLibraryWindowsImpl(HMODULE libHandle)
            : mLibHandle{ libHandle } 
        {
        }
        HMODULE mLibHandle;
    };

    DynamicLibraryWindows::DynamicLibraryWindows(HMODULE libHandle)
        : mImpl{std::make_unique<DynamicLibraryWindowsImpl>(libHandle)}
    {
    }

    DynamicLibraryWindows::~DynamicLibraryWindows() = default;

    std::unique_ptr<IDynamicLibraryFunctionPointer> DynamicLibraryWindows::getFunction(const std::string & functionName) const
    {
        void* const funProcAdress = ::GetProcAddress(mImpl->mLibHandle, functionName.c_str());
        if (funProcAdress == nullptr)
        {
            return nullptr;
        }
        return DynamicLibraryFunctionPointerWindows::makeUnique(funProcAdress);
    }

}
