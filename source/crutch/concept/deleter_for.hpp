#pragma once

namespace crutch {

template <typename Deleter, typename Type>
concept DeleterFor = requires(Type* pointer) {
  { Deleter::Delete(pointer) } noexcept;
};

}  // namespace crutch