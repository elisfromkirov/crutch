#pragma once

#include <wheel/core/core.hpp>

#include <wheel/memory/allocator.hpp>

#include <new>

namespace wheel {

class Allocator : public IAllocator {
  void* Allocate(SizeType bytes, SizeType alignment) override;

  void Deallocate(void* ptr, SizeType bytes, SizeType alignment) noexcept override;

  bool IsEqual(const IAllocator* other) const noexcept override;
};

}  // namespace wheel