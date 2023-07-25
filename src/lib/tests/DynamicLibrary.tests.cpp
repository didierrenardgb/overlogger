#include <gtest/gtest.h>

#include <overlogger/lib/dll/IDynamicLibraryLoader.h>
#include <overlogger/lib/dll/DynamicLibraryLoaderFactory.h>
#include <overlogger/lib/dll/IDynamicLibrary.h>
#include <overlogger/lib/dll/IDynamicLibraryFunctionPointer.h>
#include <overlogger/dll/DllUtils.h>

namespace olg::test
{
TEST(DynamicLibraryTest, getFunctionTest)
{
	using namespace olg::dl;
	DynamicLibraryLoaderFactory factory;
	std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
	std::unique_ptr<IDynamicLibrary> dl = loader->load(kSharedLibraryName);
	EXPECT_NE(dl->getFunction("createCallStackRetriever"), nullptr);
}

TEST(DynamicLibraryTest, failedGetFunctionTest)
{
	using namespace olg::dl;
	DynamicLibraryLoaderFactory factory;
	std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
	std::unique_ptr<IDynamicLibrary> dl = loader->load(kSharedLibraryName);
	EXPECT_EQ(dl->getFunction("thisFunctionDontExist"), nullptr);
}
} // namespace olg::test
