#pragma once

class IDynamicLibraryFunctionPointer
{
    public:
        virtual ~IDynamicLibraryFunctionPointer() = default;
    protected:
        friend class IDynamicLibraryFunctionCaller;
        virtual void* handle() const = 0;
};
