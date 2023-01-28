#pragma once

#include <concepts>
#include <type_traits>

namespace crutch {

template <typename Pointer, typename Type>
concept TrivialPointerFor = ::std::is_same_v<Pointer, Type*>;

}  // namespace crutch