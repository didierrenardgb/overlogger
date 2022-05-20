#include "CallStackLibrary.h"
#include "ICallStack.h"
#include "ICallStackFrame.h"
#include <iostream>

int main(int argc, char* argv[]){
	olg::CallStackLibrary csl;
	csl.load();
	auto csr = csl.createCallStackRetriever();
	auto cs = csr->retrieve();
	for (size_t i = 0; i < cs->getSize(); ++i)
	{
		decltype(auto) x = cs->getFrame(i);
		std::cout << x.getFunctionName() << '\n';
	}
	
    return 0;
}
