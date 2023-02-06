#include <crutch/allocator/allocator.hpp>

namespace crutch {

void* Allocator::Allocate(SizeType bytes, SizeType alignment) {
  ASSERT(bytes != 0, "number of bytes to allocate must be greater than zero");
  ASSERT(alignment != 0, "alignment must be greater than zero");

  auto ptr = ::operator new(bytes, ::std::align_val_t(alignment));
  ::std::memset(ptr, 0, bytes);
  return ptr;
}

void Allocator::Deallocate(void* ptr, SizeType bytes, SizeType alignment) noexcept {
  ASSERT(bytes != 0, "number of bytes to deallocate must be greater than zero");
  ASSERT(alignment != 0, "alignment must be greater than zero");

  if (ptr != nullptr) {
    ::operator delete(ptr, ::std::align_val_t(alignment));
  }
}

bool Allocator::IsEqual(const IAllocator* other) const noexcept {
  return this == other;
}

}  // namespace crutch