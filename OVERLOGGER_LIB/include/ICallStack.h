#pragma once

#include <vector>
#include "ICallStackFrame.h"

class ICallStack
{
public:
    virtual size_t getSize() const = 0;
    virtual const ICallStackFrame &getFrame(size_t index) const = 0;
    virtual const std::vector<ICallStackFrame> &getFrameList() const = 0;
};