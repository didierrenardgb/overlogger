#pragma once
#include <string>
#include <memory>


namespace olg::dl {
	class IDynamicLibrary;

	class IDynamicLibraryLoader {
	public:
		virtual std::unique_ptr<IDynamicLibrary> load(const std::string &path) = 0;
	};
}

//HINSTANCE hGetProcIDDLL = LoadLibrary();