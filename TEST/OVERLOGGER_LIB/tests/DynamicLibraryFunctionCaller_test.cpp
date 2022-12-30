#include <gtest/gtest.h>
#include "DynamicLibraryFunctionCaller.h"
#include "IDynamicLibraryFunctionPointer.h"

namespace olg::test
{
    int intReturnTestFunction()
    {
        return 23;
    }

    void voidReturnTestFunction() 
    {
    }

    static int kValue = 10;
    int* pointerReturnTestFunction()
    {
        int* pointer = &kValue;
        return pointer;
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

    TEST(DynamicLibraryFunctionCallerTest, call_pointerReturnTestFunction)
    {
        using namespace olg::dl;
        DynamicLibraryFunctionPointerTest dlfptr{ pointerReturnTestFunction };
        std::unique_ptr<IDynamicLibraryFunctionPointer> testFunPtr{ &dlfptr };
        Return<int*> var = call<int*>(testFunPtr);
        EXPECT_TRUE(dlfptr.handled);
        testFunPtr.release();
        EXPECT_EQ(testFunPtr.get(), nullptr);
        EXPECT_EQ(var.get(), pointerReturnTestFunction());
        var.release();
    }
}