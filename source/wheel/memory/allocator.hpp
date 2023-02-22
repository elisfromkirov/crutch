#pragma once

#include <wheel/core/core.hpp>

#include <wheel/memory/alignment.hpp>

namespace wheel {

class IAllocator {
 public:
  virtual ~IAllocator() noexcept = default;

  virtual void* Allocate(SizeType bytes, SizeType alignment) = 0;

  virtual void Deallocate(void* pointer, SizeType bytes, SizeType alignment) noexcept = 0;

  virtual bool IsEqual(const IAllocator* other) const noexcept = 0;
};

}  // namespace wheel