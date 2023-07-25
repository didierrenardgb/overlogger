#pragma once

#include <string>
#include <memory>

namespace olg::dl
{
class IDynamicLibrary;

class IDynamicLibraryLoader
{
public:
	virtual std::unique_ptr<IDynamicLibrary> load(std::string const& path) const = 0;
};
} // namespace olg::dl
