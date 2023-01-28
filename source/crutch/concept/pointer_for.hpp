#pragma once

#include <crutch/concept/trivial_pointer_for.hpp>

#include <concepts>
#include <type_traits>

namespace crutch {

template <typename Pointer, typename Type>
concept PointerFor = TrivialPointerFor<Pointer, Type> ||
    requires(Pointer pointer) {
      { pointer.operator*() } noexcept -> ::std::convertible_to<Type&>;
      { pointer.operator->() } noexcept -> ::std::convertible_to<Type*>;
    };

// еще же нужно равенство и неравенство ...

}  // namespace crutch