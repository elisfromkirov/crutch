#pragma once

#include <crutch/core/macro/assert.hpp>
#include <crutch/core/type/size.hpp>

#include <crutch/allocator/core/allocator.hpp>

#include <new>

namespace crutch {

class Allocator : public IAllocator {
 public:
  Byte* Allocate(SizeType bytes, SizeType alignment) override;

  void Deallocate(Byte* pointer, SizeType bytes, SizeType alignment) noexcept override;

  bool IsEqual(const IAllocator* other) const noexcept override;
};

}  // namespace crutch