#include <gtest/gtest.h>

#include <overlogger/lib/dll/DynamicLibraryLoaderFactory.h>
#include <overlogger/lib/dll/IDynamicLibraryLoader.h>
#include <overlogger/lib/dll/IDynamicLibrary.h>
#include <overlogger/dll/DllUtils.h>

namespace olg::test
{
TEST(DynamicLibraryLoaderTest, dlLoadTest)
{
	using namespace olg::dl;
	DynamicLibraryLoaderFactory factory;
	std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
	std::unique_ptr<IDynamicLibrary> dl = loader->load(kSharedLibraryName);
	EXPECT_NE(dl, nullptr);
}

TEST(DynamicLibraryLoaderTest, failedDlLoadTest)
{
	using namespace olg::dl;
	DynamicLibraryLoaderFactory factory;
	std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
	std::unique_ptr<IDynamicLibrary> dl = loader->load(kSharedLibraryName);
	EXPECT_EQ(dl, nullptr);
}
} // namespace olg::test
