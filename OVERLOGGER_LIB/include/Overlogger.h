#pragma once

#include <memory>

namespace olg
{
	class CallStackLibrary;

	class Overlogger
	{
	public:
		std::shared_ptr<CallStackLibrary> callStackLibrary();
		~Overlogger();
		Overlogger();
	private:
		struct OverloggerImpl;
		std::unique_ptr<OverloggerImpl> mImpl;
	};
}
