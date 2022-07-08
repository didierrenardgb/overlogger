#pragma once

#include <memory>

namespace olg 
{
	namespace dl
	{
	class IDynamicLibrary;
	class IDynamicLibraryFunctionPointer;
	}
	class ICallStackRetriever;
	class Overlogger;

	class CallStackLibrary
	{
		// TODO: la dynamic library deberia ser administrada por una clase de mayor jerarquía
	public:
		std::unique_ptr<ICallStackRetriever> createCallStackRetriever();
	private:
		friend Overlogger;
		struct CallStackLibraryImpl;
		struct MakeSharedEnabled;
		std::unique_ptr<CallStackLibraryImpl> mImpl;
		CallStackLibrary(std::shared_ptr<dl::IDynamicLibrary> const& dynamicLibrary);
		virtual ~CallStackLibrary();

		static std::shared_ptr<CallStackLibrary> makeShared(std::shared_ptr<dl::IDynamicLibrary> const& dynamicLibrary);
	};
}
