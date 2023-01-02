#ifndef NEW_ALLOCATOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type>
Type* NewAllocator<Type>::Allocate(SizeType size) noexcept {
  auto* data = new (::std::nothrow) Uint8[sizeof(Type) * size];
  ASSERT(data != nullptr, "new operator's error");
  return reinterpret_cast<Type*>(data);
}

template <typename Type>
void NewAllocator<Type>::Deallocate(Type* data) noexcept {
  delete[] reinterpret_cast<Uint8*>(data);
}

}  // namespace crutch