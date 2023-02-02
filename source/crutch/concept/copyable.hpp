#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Type>
concept Copyable = ::std::is_copy_constructible_v<Type>;

}  // namespace crutch