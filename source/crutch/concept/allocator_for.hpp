#pragma once

#include <crutch/concept/pointer_for.hpp>

#include <concepts>

namespace crutch {

template <typename Allocator, typename Type>
concept AllocatorFor = requires(Allocator allocator, Type* pointer, SizeType amount) {
  typename Allocator::Pointer;
  requires PointerFor<typename Allocator::Pointer, Type>;

  typename Allocator::ConstPointer;
  requires PointerFor<typename Allocator::ConstPointer, const Type>;

  { allocator.Allocate(amount) } noexcept -> std::convertible_to<Type*>;

  { allocator.Deallocate(pointer, amount) } noexcept;
};

}  // namespace crutch