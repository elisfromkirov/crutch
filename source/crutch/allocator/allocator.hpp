#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

#include <new>

namespace crutch {

class Allocator : public IAllocator {
 protected:
  Byte* AllocateImpl(SizeType bytes, SizeType alignment) override;

  void DeallocateImpl(Byte* pointer, SizeType bytes, SizeType alignment) noexcept override;

  bool IsEqualImpl(const IAllocator* other) const noexcept override;
};

}  // namespace crutch