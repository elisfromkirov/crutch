#pragma once

#include "source_location.hpp"

#define TO_STRING_EXPANDED(param) \
  #param

#define TO_STRING(param) \
  TO_STRING_EXPANDED(param)

#define CONCAT_EXPANDED(x, y) \
  x##y

#define CONCAT(x, y) \
  CONCAT_EXPANDED(x, y)

#define HERE() \
  crutch::SourceLocation{__FILE__, __LINE__, __func__}
