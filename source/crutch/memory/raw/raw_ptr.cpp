#include <crutch/allocator/core/allocator.hpp>

#include <crutch/core/macro/assert.hpp>

#include <crutch/memory/raw/raw_ptr.hpp>

namespace crutch {

RawPtr::RawPtr(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept
    : RawPtrBase{pointer, allocator, bytes, alignment} {
  ASSERT(pointer != nullptr, "pointer must be a valid pointer");
  ASSERT(allocator != nullptr, "allocator must be a valid pointer");
}

Byte* RawPtr::Get() const noexcept {
  return pointer_;
}

void RawPtr::Release() noexcept {
  pointer_ = nullptr;
}

}  // namespace crutch