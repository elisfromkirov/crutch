#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Deleter, typename Type>
concept DeleterFor = requires(Deleter deleter, Type* object) {
  requires std::is_nothrow_move_constructible_v<Deleter>;
  requires std::is_nothrow_move_assignable_v<Deleter>;
  { deleter(object) } noexcept;
};

}  // namespace crutch