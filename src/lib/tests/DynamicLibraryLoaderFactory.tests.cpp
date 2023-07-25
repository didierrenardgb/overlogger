#include <memory>

#include <gtest/gtest.h>

#include <overlogger/lib/dll/DynamicLibraryLoaderFactory.h>
#include <overlogger/lib/dll/IDynamicLibraryLoader.h>

namespace olg::test
{
TEST(DynamicLibraryLoaderFactoryTest, createDynamicLibraryLoaderTest)
{
	using namespace olg::dl;
	DynamicLibraryLoaderFactory factory;
	std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
	EXPECT_NE(loader, nullptr);
}
} // namespace olg::test
