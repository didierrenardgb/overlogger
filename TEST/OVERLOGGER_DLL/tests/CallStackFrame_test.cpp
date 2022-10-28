#include <gtest/gtest.h>
#include "CallStackFrame.h"

namespace olg::test 
{
    TEST(CallStackFrameTest, ConstructionAndGettersTest)
    {
        //CallStackFrame(unsigned long long address, const std::string &functionName, const std::string &sourceFileName,unsigned long codeLine);
        unsigned long long address = 0x1000;
        const std::string funName = "myTestFunName";
        const std::string srcFileName = "mySrcFileName";
        unsigned long codeLine = 0x500;
        CallStackFrame csf{ address, funName, srcFileName, codeLine };
        EXPECT_EQ(address, csf.getAddress());
        EXPECT_EQ(funName, csf.getFunctionName());
        EXPECT_EQ(srcFileName, csf.getSourceFileName());
        EXPECT_EQ(codeLine, csf.getCodeLine());
    }
}