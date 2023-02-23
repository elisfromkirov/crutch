#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

constexpr SizeType kMaxAlignment = alignof(::std::max_align_t);

}  // namespace wheels