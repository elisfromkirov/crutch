#pragma once

#define TO_STRING_EXPANDED(x) \
  #x

#define TO_STRING(x) \
  TO_STRING_EXPANDED(x)