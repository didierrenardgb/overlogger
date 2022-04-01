class DynamicLibraryFunctionPointerWindows : public IDynamicLibraryFunctionPointer
{
        ~DynamicLibraryFunctionPointerWindows() = default;
    protected:
        DynamicLibraryFunctionPointerWindows(void*);
        DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows const& other) = delete;
        DynamicLibraryFunctionPointerWindows(DynamicLibraryFunctionPointerWindows&& other) = delete;
        void* handle() const override;
        friend class DynamicLibraryWindows;
        class DynamicLibraryFunctionPointerWindowsImpl;
        std::unique_ptr<DynamicLibraryFunctionPointerImpl> mImpl;
};