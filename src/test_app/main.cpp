#include <iostream>

#include <overlogger/dll/callstack/ICallStack.h>
#include <overlogger/dll/callstack/ICallStackFrame.h>
#include <overlogger/dll/callstack/ICallStackRetriever.h>

#include <overlogger/lib/callstack/CallStackLibrary.h>
#include <overlogger/lib/Overlogger.h>

int main(int argc, char* argv[])
{
	olg::Overlogger overlogger;
	auto lib = overlogger.callStackLibrary();
	auto ret = lib->createCallStackRetriever();
	auto cs = ret->retrieve();

	auto frame = lib->equals(cs->getFrame(0), lib->getCallStackFrameNull());
	for (size_t i = 0; i < cs->getSize(); ++i)
	{
		const auto& fr = cs->getFrame(i);
		std::cout << fr.getSourceFileName() << ':' << fr.getCodeLine() << ' ' << fr.getFunctionName() << '\n';
	}
    return 0;
}
