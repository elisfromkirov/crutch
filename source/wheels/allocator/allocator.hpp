#pragma once

#include <wheels/core/core.hpp>

#include <wheels/memory/allocator.hpp>

#include <new>

namespace wheels {

class Allocator : public IAllocator {
  void* Allocate(SizeType bytes, SizeType alignment) override;

  void Deallocate(void* ptr, SizeType bytes, SizeType alignment) noexcept override;

  bool IsEqual(const IAllocator* other) const noexcept override;
};

}  // namespace wheels