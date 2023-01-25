#pragma once

#include <type_traits>

namespace crutch {

template <typename Type>
concept IsNotReference = !std::is_reference<Type>::value;

}  // namespace crutch