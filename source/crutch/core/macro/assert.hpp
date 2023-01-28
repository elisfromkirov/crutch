#pragma once

#include <cassert>

#define ASSERT(expression, message)    \
  do {                                 \
    if (!(expression)) {               \
      assert((expression) || message); \
    }                                  \
  } while (false)
