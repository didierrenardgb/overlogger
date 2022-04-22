#pragma once
#include <memory>
#include <string>

namespace olg::dl {
    class IDynamicLibraryFunctionPointer;
	class IDynamicLibrary {
    public:
        virtual std::unique_ptr<IDynamicLibraryFunctionPointer> getFunction(const std::string &functionName) const = 0;
	};
}