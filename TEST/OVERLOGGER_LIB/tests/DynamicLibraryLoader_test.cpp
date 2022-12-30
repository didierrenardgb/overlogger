#include <gtest/gtest.h>
#include "DynamicLibraryLoaderFactory.h"
#include "IDynamicLibraryLoader.h"
#include "IDynamicLibrary.h"

namespace olg::test
{
	TEST(DynamicLibraryLoaderTest, dlLoadTest)
	{
		using namespace olg::dl;
		DynamicLibraryLoaderFactory factory;
		std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
		std::unique_ptr<IDynamicLibrary> dl = loader->load("OVERLOGGER_DLL");
		EXPECT_NE(dl, nullptr);
	}

	TEST(DynamicLibraryLoaderTest, failedDlLoadTest)
	{
		using namespace olg::dl;
		DynamicLibraryLoaderFactory factory;
		std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
		std::unique_ptr<IDynamicLibrary> dl = loader->load("OVERTROLLER_DLL");
		EXPECT_EQ(dl, nullptr);
	}
}