#pragma once

#include <type_traits>

namespace crutch {

template <typename Type>
concept MoveConstructible = ::std::is_nothrow_move_constructible_v<Type>;

}  // namespace crutch