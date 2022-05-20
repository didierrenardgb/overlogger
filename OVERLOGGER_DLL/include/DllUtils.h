#pragma once

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#error "TODO other platforms"
#endif