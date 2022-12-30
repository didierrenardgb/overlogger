#include <gtest/gtest.h>
#include "IDynamicLibraryLoader.h"
#include "DynamicLibraryLoaderFactory.h"
#include "IDynamicLibrary.h"
#include "IDynamicLibraryFunctionPointer.h"

namespace olg::test
{
	TEST(DynamicLibraryTest, getFunctionTest)
	{
		using namespace olg::dl;
		DynamicLibraryLoaderFactory factory;
		std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
		std::unique_ptr<IDynamicLibrary> dl = loader->load("OVERLOGGER_DLL");
		EXPECT_NE(dl->getFunction("createCallStackRetriever"), nullptr);
	}

	TEST(DynamicLibraryTest, failedGetFunctionTest)
	{
		using namespace olg::dl;
		DynamicLibraryLoaderFactory factory;
		std::unique_ptr<IDynamicLibraryLoader> loader = factory.create();
		std::unique_ptr<IDynamicLibrary> dl = loader->load("OVERLOGGER_DLL");
		EXPECT_EQ(dl->getFunction("thisFunctionDontExist"), nullptr);
	}
}