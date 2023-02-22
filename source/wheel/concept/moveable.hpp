#pragma once

#include <wheel/core/core.hpp>

namespace wheel {

template <typename Type>
concept Moveable = ::std::is_nothrow_move_constructible_v<Type>;

}  // namespace wheel