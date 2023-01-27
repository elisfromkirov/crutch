#pragma once

#include <crutch/core/assert.hpp>
#include <crutch/core/types.hpp>

#include <crutch/concept/constructible.hpp>

#include <new>

namespace crutch {

template <typename Type>
class Allocator {
 public:
  using Pointer = Type*;
  using ConstPointer = const Type*;

 public:
  [[nodiscard]]
  Pointer Allocate(SizeType amount) noexcept;

  void Deallocate(Pointer pointer, SizeType amount) noexcept;
};

}  // namespace crutch

#define ALLOCATOR_IMPL
#include <crutch/allocator/allocator.ipp>
#undef ALLOCATOR_IMPL