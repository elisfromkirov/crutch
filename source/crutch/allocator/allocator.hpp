#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

namespace crutch {

class Allocator : public IAllocator {
 public:
  Byte* Allocate(SizeType bytes, SizeType alignment) override;

  void Deallocate(Byte* pointer, SizeType bytes, SizeType alignment) noexcept override;

  bool IsEqual(const IAllocator* other) const noexcept override;
};

}  // namespace crutch