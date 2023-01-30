#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Pointer, typename Type>
concept TrivialPointerFor = ::std::is_same_v<Pointer, Type*>;

}  // namespace crutch