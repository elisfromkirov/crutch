#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Type>
concept Moveable = ::std::is_nothrow_move_constructible_v<Type>;

}  // namespace crutch