#pragma once

#include <type_traits>

namespace crutch {

template <typename Type, typename... ArgTypes>
concept Constructible = std::is_constructible<Type, ArgTypes...>::value;

}  // namespace crutch