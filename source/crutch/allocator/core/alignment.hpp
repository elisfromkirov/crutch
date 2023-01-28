#pragma once

#include <crutch/core/type/size.hpp>

namespace crutch {

constexpr SizeType kMaxAlignment = alignof(::std::max_align_t);

}  // namespace crutch