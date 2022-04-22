#pragma once

namespace olg::dl
{
    template<class RetType, typename... Args>
    class DynamicLibraryFunctionCaller : public IDynamicLibraryFunctionCaller
    {
    public:
        DynamicLibraryFunctionCaller(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer, std::function<void(RetType&&)> onCalled, Args&& args...) :
            mFunctionPointer(functionPointer)
            , mOnCalled(onCalled)
            , mArgs(std::move(args))
        {
        }
        void call() const
        {
            onCalled(std::apply(handle(mFunctionPointer), mArgs));
        }
    private:
        std::unique_ptr<IDynamicLibraryFunctionPointer> const& mFunctionPointer;
        std::function<void(RetType&&)> mOnCalled;
        std::tuple<Args...> mArgs;
    };

    template<class RetType, typename... Args>
    void call(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer, std::function<void(RetType&&)> onCalled, Args&& args...)
    {
        DynamicLibraryFunctionCaller caller(functionPointer, onCalled, args...);
        caller.call();
    }
}