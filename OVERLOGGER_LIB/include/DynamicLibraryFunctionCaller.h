#pragma once

#include <functional>
#include <memory>
#include <type_traits>

#include "IDynamicLibraryFunctionCaller.h"
#include "IDynamicLibraryFunctionPointer.h"

namespace olg::dl
{
    template<class T>
    using Return = typename std::conditional<std::is_const_v<std::remove_pointer_t<T>>,
        T,
        typename std::conditional<std::is_pointer_v<T>,
            std::unique_ptr<std::remove_pointer_t<T>>,
            T
            >::type
        >::type;

    template<class RetType, typename... Args>
    class DynamicLibraryFunctionCaller : public IDynamicLibraryFunctionCaller
    {
    public:
        using OnCalledType = std::function<void(Return<RetType>&&)>;

        DynamicLibraryFunctionCaller(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer, OnCalledType const& onCalled, Args&&... args) :
            mFunctionPointer(functionPointer)
            , mOnCalled(onCalled)
            , mArgs(std::forward<Args>(args)...)
        {
        }
        
        DynamicLibraryFunctionCaller(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer, Args&&... args) :
            mFunctionPointer(functionPointer)
            , mOnCalled(nullptr)
            , mArgs(std::forward<Args>(args)...)
        {
        }

        void call() const override
        {
            // TODO: RetType void
            if constexpr (!std::is_const_v<std::remove_pointer_t<RetType>> && std::is_pointer_v<RetType>)
            {
                RetType result = std::apply(reinterpret_cast<RetType(*)(Args...)>(handle(mFunctionPointer)), mArgs);
                mOnCalled(std::unique_ptr<std::remove_pointer_t<RetType>>(result));
            }
            else
            {
                mOnCalled(std::apply(reinterpret_cast<RetType(*)(Args...)>(handle(mFunctionPointer)), mArgs));
            }
        }

    private:

        std::unique_ptr<IDynamicLibraryFunctionPointer> const& mFunctionPointer;
        OnCalledType mOnCalled;
        std::tuple<Args...> mArgs;
    };

    template<class RetType, typename... Args>
    Return<RetType> call(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer, Args&&... args)
    {
        Return<RetType> result;
        DynamicLibraryFunctionCaller<RetType, Args...> caller(functionPointer, [&result](Return<RetType>&& ret)
        {
            result = std::move(ret);
        }, std::forward<Args>(args)...);
        caller.call();
        return result;
    }

    template<typename... Args>
    void call(std::unique_ptr<IDynamicLibraryFunctionPointer> const& functionPointer, Args&&... args)
    {
        DynamicLibraryFunctionCaller<void, Args...> caller(functionPointer, std::forward<Args>(args)...);
        caller.call();
    }
}
