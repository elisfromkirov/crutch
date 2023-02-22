#pragma once

#include <wheel/core/core.hpp>

namespace wheel {

template <typename Type, typename... Arguments>
concept Constructible = ::std::is_constructible_v<Type, Arguments...>;

template <typename Type, typename... Arguments>
constexpr bool kIsNothrowConstructible = ::std::is_nothrow_constructible_v<Type, Arguments...>;

}  // namespace wheel