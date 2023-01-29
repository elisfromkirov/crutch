#pragma once

#include <crutch/core/type/size.hpp>

namespace crutch {

class IAllocator {
 public:
  virtual ~IAllocator() noexcept = default;

  virtual Byte* Allocate(SizeType bytes, SizeType alignment) = 0;

  virtual void Deallocate(Byte* pointer, SizeType bytes, SizeType alignment) noexcept = 0;

  virtual bool IsEqual(const IAllocator* other) const noexcept = 0;
};

}  // namespace crutch