#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Type>
concept CopyAssignable = std::is_copy_assignable_v<Type>;

template <typename Type>
concept MoveAssignable = std::is_nothrow_move_assignable_v<Type>;

}  // namespace crutch