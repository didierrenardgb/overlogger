struct DynamicLibraryFunctionPointerWindows::DynamicLibraryFunctionPointerWindowsImpl
{
    void* mFunctionPointer;
};
void* DynamicLibraryFunctionPointerWindows::handle() const
{
    return mImpl->mFunctionPointer;
}
