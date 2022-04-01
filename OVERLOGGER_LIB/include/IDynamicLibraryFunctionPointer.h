class IDynamicLibraryFunctionPointer
{
    public:
        virtual ~DynamicLibraryFunctionPointer() = default;
    protected:
        friend class IDynamicLibraryFunctionCaller;
        virtual void* handle() const = 0;
};
