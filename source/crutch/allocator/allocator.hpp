#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

#include <new>

namespace crutch {

class Allocator : public IAllocator {
  void* Allocate(SizeType bytes, SizeType alignment) override;

  void Deallocate(void* ptr, SizeType bytes, SizeType alignment) noexcept override;

  bool IsEqual(const IAllocator* other) const noexcept override;
};

}  // namespace crutch