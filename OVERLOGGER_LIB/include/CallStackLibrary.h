#pragma once

#include "IDynamicLibrary.h"
#include "IDynamicLibraryFunctionPointer.h"
#include "ICallStackRetriever.h"

namespace olg 
{
	class CallStackLibrary
	{
		// TODO: la dynamic library se deberia encargar de administrar
	private:
		std::shared_ptr<dl::IDynamicLibrary> mDynamicLibrary;
		std::unique_ptr<dl::IDynamicLibraryFunctionPointer> mCreateCallStackRetriever;
	public:
		void load();
		std::unique_ptr<ICallStackRetriever> createCallStackRetriever();
	};
}