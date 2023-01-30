#include <crutch/memory/allocator.hpp>

namespace crutch {

Byte* IAllocator::Allocate(SizeType bytes, SizeType alignment) {
  return AllocateImpl(bytes, alignment);
}

void IAllocator::Deallocate(Byte* pointer, SizeType bytes, SizeType alignment) noexcept {
  DeallocateImpl(pointer, bytes, alignment);
}

bool IAllocator::IsEqual(const IAllocator* other) const noexcept {
  return IsEqualImpl(other);
}

}  // namespace crutch