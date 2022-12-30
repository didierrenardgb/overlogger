#include <gtest/gtest.h>
#include "DynamicLibraryLoaderFactory.h"
#include "IDynamicLibraryLoader.h"
#include <memory>

namespace olg::test
{
	TEST(DynamicLibraryLoaderFactoryTest, createDynamicLibraryLoaderTest)
	{
		using namespace olg::dl;
		DynamicLibraryLoaderFactory factory;
		std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
		EXPECT_NE(loader, nullptr);
	}
}