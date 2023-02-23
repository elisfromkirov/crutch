#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

template <typename Type>
concept Moveable = ::std::is_nothrow_move_constructible_v<Type>;

}  // namespace wheels