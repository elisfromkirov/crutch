#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/alignment.hpp>

namespace crutch {

class IAllocator {
 public:
  virtual ~IAllocator() noexcept = default;

  virtual void* Allocate(SizeType bytes, SizeType alignment) = 0;

  virtual void Deallocate(void* pointer, SizeType bytes, SizeType alignment) noexcept = 0;

  virtual bool IsEqual(const IAllocator* other) const noexcept = 0;
};

}  // namespace crutch