#pragma once

#include <wheel/core/core.hpp>

namespace wheel {

template <typename Type>
concept Copyable = ::std::is_copy_constructible_v<Type>;

}  // namespace wheel