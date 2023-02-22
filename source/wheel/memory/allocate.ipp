#ifndef ALLOCATE_IMPL
#error Do not include this file directly
#endif

namespace wheel {

template <typename Type>
RawPtr<Type> Allocate(IAllocator* allocator) {
  ASSERT(allocator != nullptr, "allocator must be a valid pointer");

  return RawPtr<Type>{static_cast<Type*>(allocator->Allocate(sizeof(Type), alignof(Type))), allocator};
}

}  // namespace wheel