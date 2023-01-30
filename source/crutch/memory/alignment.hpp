#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

constexpr SizeType kMaxAlignment = alignof(::std::max_align_t);

}  // namespace crutch