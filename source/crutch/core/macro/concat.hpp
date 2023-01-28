#pragma once

#define CONCAT_EXPANDED(x, y) \
  x##y

#define CONCAT(x, y) \
  CONCAT_EXPANDED(x, y)