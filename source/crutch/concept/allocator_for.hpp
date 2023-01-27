#pragma once

#include <concepts>

namespace crutch {

template <typename Allocator, typename Type>
concept AllocatorFor = requires(Type* pointer) {
  { Allocator::Allocate() } noexcept -> std::convertible_to<Type*>;
  { Allocator::Deallocate(pointer) } noexcept;
};

}  // namespace crutch