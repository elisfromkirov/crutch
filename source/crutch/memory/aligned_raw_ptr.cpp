#include <crutch/memory/aligned_raw_ptr.hpp>

namespace crutch {

AlignedRawPtr::AlignedRawPtr(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept
    : AlignedRawPtrBase{pointer, allocator, bytes, alignment} {
  ASSERT(pointer != nullptr, "pointer must be a valid pointer");
  ASSERT(allocator != nullptr, "allocator must be a valid pointer");
}

Byte* AlignedRawPtr::Get() const noexcept {
  return pointer_;
}

void AlignedRawPtr::Release() noexcept {
  pointer_ = nullptr;
}

}  // namespace crutch