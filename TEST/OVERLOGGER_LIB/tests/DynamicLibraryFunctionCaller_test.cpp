#include <gtest/gtest.h>
#include "DynamicLibraryFunctionCaller.h"
#include "IDynamicLibraryFunctionPointer.h"

/*
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
*/

namespace olg::test
{
    int intReturnTestFunction()
    {
        return 23;
    }

    void voidReturnTestFunction() 
    {
    }

    static int number = 42;
    int& intRefReturnTestFunction()
    {
        return number;
    }

    class DynamicLibraryFunctionPointerTest : public olg::dl::IDynamicLibraryFunctionPointer
    {
    public:
        mutable bool handled = false;
        DynamicLibraryFunctionPointerTest(void* function) : mFunction{function}
        {}

    private:
        void* mFunction;
        void* handle() const 
        {
            handled = true;
            return mFunction;
        }

    };

    /*
        nada
        value
        lval reference
        rval reference
        callable object
        pointer
    */

    TEST(DynamicLibraryFunctionCallerTest, call_intReturnTestFunction)
    {
        using namespace olg::dl;
        DynamicLibraryFunctionPointerTest dlfptr{ intReturnTestFunction };
        std::unique_ptr<IDynamicLibraryFunctionPointer> testFunPtr{&dlfptr};
        Return<int> var = call<int>(testFunPtr);
        EXPECT_TRUE(dlfptr.handled);
        testFunPtr.release();
        EXPECT_EQ(testFunPtr.get(), nullptr);
        EXPECT_EQ(var, intReturnTestFunction());
    }

    TEST(DynamicLibraryFunctionCallerTest, call_voidReturnTestFunction)
    {
        using namespace olg::dl;
        DynamicLibraryFunctionPointerTest dlfptr{ voidReturnTestFunction };
        std::unique_ptr<IDynamicLibraryFunctionPointer> testFunPtr{ &dlfptr };
        call<>(testFunPtr);
        EXPECT_TRUE(dlfptr.handled);
        testFunPtr.release();
        EXPECT_EQ(testFunPtr.get(), nullptr);
    }
}