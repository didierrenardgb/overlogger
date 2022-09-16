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
	// TODO: falta cargar el simbolo para comparar CallStackFrames. renombrar equals para evitar problemas en C por los nombres iguales
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
} // namespace olg
