#include <crutch/memory/raw_ptr.hpp>

namespace crutch {

RawPtr::RawPtr(Byte* pointer, IAllocator* allocator, SizeType bytes) noexcept
    : RawPtrBase{pointer, allocator, bytes} {
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