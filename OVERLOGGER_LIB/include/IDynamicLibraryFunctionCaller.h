class IDynamicLibraryFunctionCaller
{
    public:
        virtual void call() const = 0;
    protected:
        virtual void* handle(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer) const
        {
            return functionPointer->handle();
        }
};