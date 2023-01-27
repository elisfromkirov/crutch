#pragma once

#include <type_traits>

namespace crutch {

template <typename Type, typename... ArgTypes>
concept ConstructibleFrom = std::is_constructible<Type, ArgTypes...>::value;

}  // namespace crutch