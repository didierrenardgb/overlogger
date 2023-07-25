#pragma once

#include <memory>

namespace olg::dl
{
class IDynamicLibraryLoader;

class DynamicLibraryLoaderFactory
{
public:
	std::unique_ptr<IDynamicLibraryLoader> create() const;
};
} // namespace olg::dl
