#pragma once

#include <concepts>
#include <type_traits>

namespace crutch {

template <typename Pointer, typename Type>
concept TrivialPointerFor = ::std::is_same<Pointer, Type*>::value;

}  // namespace crutch