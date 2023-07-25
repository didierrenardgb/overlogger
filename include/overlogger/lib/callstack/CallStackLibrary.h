#pragma once

#include <memory>
#include <string_view>

namespace olg
{
namespace dl
{
class IDynamicLibrary;
class IDynamicLibraryFunctionPointer;
}
class ICallStackRetriever;
class Overlogger;
class ICallStackFrame;

class CallStackLibrary
{
public:
	std::unique_ptr<ICallStackRetriever> createCallStackRetriever();
	bool equals(ICallStackFrame const& frame1, ICallStackFrame const& frame2);
	ICallStackFrame const& getCallStackFrameNull();
	std::string_view const& getNullString();

private:
	friend Overlogger;
	struct MakeSharedEnabled;

	CallStackLibrary(std::shared_ptr<dl::IDynamicLibrary> const& dynamicLibrary);
	virtual ~CallStackLibrary();

	static std::shared_ptr<CallStackLibrary> makeShared(std::shared_ptr<dl::IDynamicLibrary> const& dynamicLibrary);

	struct CallStackLibraryImpl;
	std::unique_ptr<CallStackLibraryImpl> mImpl;
};
} // namespace olg
