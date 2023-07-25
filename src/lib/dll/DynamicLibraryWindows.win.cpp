#include "DynamicLibraryWindows.win.h"
#include "DynamicLibraryFunctionPointerWindows.win.h"

namespace olg::dl
{
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

std::unique_ptr<IDynamicLibraryFunctionPointer> DynamicLibraryWindows::getFunction(std::string const& functionName) const
{
    void* const funProcAdress = ::GetProcAddress(mImpl->mLibHandle, functionName.c_str());
    if (funProcAdress == nullptr)
    {
        return nullptr;
    }
    return DynamicLibraryFunctionPointerWindows::makeUnique(funProcAdress);
}
} // namespace olg::dl
