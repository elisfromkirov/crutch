#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Type, typename... ArgTypes>
concept Constructible = ::std::is_constructible_v<Type, ArgTypes...>;

template <typename Type>
concept DefaultConstructible = ::std::is_default_constructible_v<Type>;

template <typename Type>
concept CopyConstructible = ::std::is_copy_constructible_v<Type>;

template <typename Type>
concept MoveConstructible = ::std::is_nothrow_move_constructible_v<Type>;

}  // namespace crutch