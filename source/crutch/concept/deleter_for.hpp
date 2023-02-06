#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Deleter, typename Type>
concept DeleterFor = requires(Deleter deleter, Type* object) {
  requires std::is_nothrow_copy_constructible_v<Deleter>;
  { deleter(object) } noexcept;
};

}  // namespace crutch