#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

template <typename Deleter, typename Type>
concept DeleterFor = requires(Deleter deleter, Type* object) {
  requires std::is_nothrow_copy_constructible_v<Deleter>;
  { deleter(object) } noexcept;
};

}  // namespace wheels