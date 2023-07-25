#include <gtest/gtest.h>

#include <overlogger/lib/Overlogger.h>
#include <overlogger/lib/callstack/CallStackLibrary.h>

namespace olg::test
{
TEST(OverloggerTest, getCallStackLibraryTest)
{
	using namespace olg::dl;
	Overlogger olg;
	EXPECT_NE(olg.callStackLibrary(), nullptr);
}
} // namespace olg::test
