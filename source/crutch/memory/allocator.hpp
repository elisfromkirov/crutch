#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/alignment.hpp>

namespace crutch {

class IAllocator {
 public:
  virtual ~IAllocator() noexcept = default;

  Byte* Allocate(SizeType bytes, SizeType alignment = kMaxAlignment);

  void Deallocate(Byte* pointer, SizeType bytes, SizeType alignment = kMaxAlignment) noexcept;

  bool IsEqual(const IAllocator* other) const noexcept;

 protected:
  virtual Byte* AllocateImpl(SizeType bytes, SizeType alignment) = 0;

  virtual void DeallocateImpl(Byte* pointer, SizeType bytes, SizeType alignment) noexcept = 0;

  virtual bool IsEqualImpl(const IAllocator* other) const noexcept = 0;
};

}  // namespace crutch