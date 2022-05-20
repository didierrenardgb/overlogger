#include "CallStackLibrary.h"
#include "ICallStackRetriever.h"
#include "DynamicLibraryLoaderWindows.h"
#include "DynamicLibraryFunctionCaller.h"

namespace olg {

void CallStackLibrary::load()
{
	using namespace dl;
	if (!mDynamicLibrary) {
		std::unique_ptr<IDynamicLibraryLoader> loader = std::make_unique<DynamicLibraryLoaderWindows>(); // TODO: factory dl loaders
		mDynamicLibrary = std::shared_ptr<IDynamicLibrary>(loader->load("overlogger_dll.dll").release()); // TODO: resolucion de nombres liberia dinamica
	}
}
std::unique_ptr<ICallStackRetriever> CallStackLibrary::createCallStackRetriever()
{
	using namespace dl;
	if (!mCreateCallStackRetriever)
	{
		mCreateCallStackRetriever = mDynamicLibrary->getFunction("createCallStackRetriever");
	}
	return call<ICallStackRetriever*>(mCreateCallStackRetriever);
}
}