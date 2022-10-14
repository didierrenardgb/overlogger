#include "CallStackLibrary.h"
#include "ICallStack.h"
#include "ICallStackFrame.h"
#include "ICallStackRetriever.h"
#include "Overlogger.h"
#include <iostream>

int main(int argc, char* argv[]){
	olg::Overlogger overlogger;
	auto lib = overlogger.callStackLibrary();
	auto ret = lib->createCallStackRetriever();
	auto cs = ret->retrieve();

	auto frame = lib->equals(cs->getFrame(0), lib->createCallStackFrameNull());
	for (size_t i = 0; i < cs->getSize(); ++i)
	{
		const auto& fr = cs->getFrame(i);
		std::cout << fr.getSourceFileName() << ':' << fr.getCodeLine() << ' ' << fr.getFunctionName() << '\n';
	}
    return 0;
}
