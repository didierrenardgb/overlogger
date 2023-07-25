#pragma once

#include <vector>
#include <memory>

namespace olg
{
class ICallStackFrame;

class ICallStack
{
public:
    virtual ~ICallStack() = default;
    virtual size_t getSize() const = 0;
    virtual ICallStackFrame const& getFrame(size_t index) const = 0;
    virtual std::vector<std::unique_ptr<ICallStackFrame>> const& getFrameList() const = 0;
};
} // namespace olg
