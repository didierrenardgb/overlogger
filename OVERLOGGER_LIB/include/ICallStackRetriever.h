#pragma once
#include "CallStack.h"

class ICallStackRetriever {
public:
    virtual CallStack retrieve() = 0;
};