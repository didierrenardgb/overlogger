#include "CallStackLibrary.h"
#include "ICallStack.h"
#include "ICallStackFrame.h"
#include "ICallStackRetriever.h"
#include "Overlogger.h"
#include <iostream>

int main(int argc, char* argv[]){
	olg::Overlogger overlogger;
	auto csr = overlogger.callStackLibrary()->createCallStackRetriever();
	auto cs = csr->retrieve();
	for (size_t i = 0; i < cs->getSize(); ++i)
	{
		decltype(auto) x = cs->getFrame(i);
		std::cout << x.getFunctionName() << '\n';
	}
	
    return 0;
}
