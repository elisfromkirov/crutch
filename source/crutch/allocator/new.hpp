#pragma once

#include <crutch/core/assert.hpp>
#include <crutch/core/types.hpp>

#include <crutch/utiltiy/placement.hpp>

namespace crutch {

template <typename Type>
class NewAllocator {
 public:
  static Type* Allocate(SizeType size) noexcept;

  static void Deallocate(Type* data) noexcept;
};

}  // namespace crutch

#define NEW_IMPL
#include <crutch/allocator/new.ipp>
#undef NEW_IMPL
