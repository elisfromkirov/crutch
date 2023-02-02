#include <crutch/allocator/allocator.hpp>

namespace crutch {

void* Allocator::Allocate(SizeType bytes, SizeType alignment) {
  ASSERT(bytes != 0, "number of bytes to allocate must be greater than zero");
  ASSERT(alignment != 0, "alignment must be greater than zero");

  return ::operator new(bytes, ::std::align_val_t(alignment));
}

void Allocator::Deallocate(void* pointer, SizeType bytes, SizeType alignment) noexcept {
  ASSERT(bytes != 0, "number of bytes to deallocate must be greater than zero");
  ASSERT(alignment != 0, "alignment must be greater than zero");

  if (pointer != nullptr) {
    ::operator delete(pointer, std::align_val_t(alignment));
  }
}

bool Allocator::IsEqual(const IAllocator* other) const noexcept {
  return this == other;
}

}  // namespace crutch