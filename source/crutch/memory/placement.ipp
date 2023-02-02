#ifndef PLACEMENT_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes&&...>
Type* Construct(RawPtr<Type> ptr, ArgTypes&&... args) {
  auto pointer = ConstructAt(ptr.Get(), ::std::forward<ArgTypes>(args)...);
  ptr.Release();
  return pointer;
}

template <typename Type>
RawPtr<Type> Destroy(Type* object, IAllocator* allocator) noexcept {
  ASSERT(allocator != nullptr, "allocator must be a valid pointer");

  DestroyAt(object);
  return RawPtr<Type>{object, allocator};
}

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes&&...>
Type* ConstructAt(Type* ptr, ArgTypes&&... args) {
  ASSERT(ptr != nullptr, "ptr must be a valid pointer");

  return new (ptr) Type(::std::forward<ArgTypes>(args)...);
}

template <typename Type>
void DestroyAt(Type* object) noexcept {
  if (object != nullptr) {
    object->~Type();
  }
}

}  // namespace crutch