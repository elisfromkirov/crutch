#pragma once

#include <type_traits>

namespace crutch {

template <typename Type>
concept CopyConstructible = ::std::is_copy_constructible_v<Type>;

}  // namespace crutch