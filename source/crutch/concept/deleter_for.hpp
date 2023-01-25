#pragma once

namespace crutch {

template <typename Type, typename Deleter>
concept DeleterFor = requires(Type* pointer) {
  { Deleter::Delete(pointer) } noexcept;
};

}  // namespace crutch