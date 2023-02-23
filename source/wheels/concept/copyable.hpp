#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

template <typename Type>
concept Copyable = ::std::is_copy_constructible_v<Type>;

}  // namespace wheels