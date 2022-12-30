#include <gtest/gtest.h>
#include "Overlogger.h"
#include "CallStackLibrary.h"

namespace olg::test
{
	TEST(OverloggerTest, getCallStackLibraryTest)
	{
		using namespace olg::dl;
		Overlogger olg;
		EXPECT_NE(olg.callStackLibrary(), nullptr);
	}
}