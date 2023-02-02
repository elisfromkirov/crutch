#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Type, typename... ArgTypes>
concept Constructible = ::std::is_constructible_v<Type, ArgTypes...>;

}  // namespace crutch