#pragma once

#include <crutch/concept/assignable.hpp>
#include <crutch/concept/constructible.hpp>

namespace crutch {

template <typename Deleter, typename Type>
concept DeleterFor = MoveConstructible<Deleter> && MoveAssignable<Deleter> &&
    requires(Deleter deleter, Type* pointer) {
      { deleter(pointer) } noexcept;
    };

}  // namespace crutch