#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define HEADER_ONLY_EXPORT __declspec(dllexport)
#else
  #define HEADER_ONLY_EXPORT
#endif

HEADER_ONLY_EXPORT inline int add(int a, int b) {
    return a + b;
}