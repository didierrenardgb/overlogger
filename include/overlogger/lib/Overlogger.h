#pragma once

#include <memory>

namespace olg
{
class CallStackLibrary;

class Overlogger
{
public:
	Overlogger();
	~Overlogger();

	std::shared_ptr<CallStackLibrary> callStackLibrary();

private:
	struct OverloggerImpl;
	std::unique_ptr<OverloggerImpl> mImpl;
};
}
