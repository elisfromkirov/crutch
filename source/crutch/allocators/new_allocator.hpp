#pragma once

#include <crutch/core/assert.hpp>
#include <crutch/core/types.hpp>
#include <crutch/core/utility.hpp>

namespace crutch {

template <typename Type>
class NewAllocator {
 public:
  Type* Allocate(SizeType size) noexcept;

  void Deallocate(Type* data) noexcept;
};

}  // namespace crutch

#define NEW_ALLOCATOR_IMPL
#include <crutch/allocators/new_allocator.ipp>
#undef NEW_ALLOCATOR_IMPL
