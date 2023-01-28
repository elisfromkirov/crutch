#pragma once

#include "crutch/allocator/core/allocator.hpp"
#include "raw_ptr.hpp"

namespace crutch {

RawPtr::RawPtr(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept
    : RawPtrBase{pointer, allocator, bytes, alignment} {
}

Byte* RawPtr::Get() const noexcept {
  return pointer_;
}

void RawPtr::Release() noexcept {
  pointer_ = nullptr;
}

}  // namespace crutch