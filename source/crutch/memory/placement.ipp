#ifndef PLACEMENT_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename... Arguments>
requires Constructible<Type, Arguments&&...>
Type* Construct(RawPtr<Type> ptr, Arguments&&... arguments) noexcept(kIsNothrowConstructible<Type, Arguments&&...>) {
  auto pointer = ConstructAt(ptr.Get(), ::std::forward<Arguments>(arguments)...);
  ptr.Release();
  return pointer;
}

template <typename Type>
RawPtr<Type> Destroy(Type* object, IAllocator* allocator) noexcept {
  ASSERT(allocator != nullptr, "allocator must be a valid pointer");

  DestroyAt(object);
  return RawPtr<Type>{object, allocator};
}

template <typename Type, typename... Arguments>
requires Constructible<Type, Arguments&&...>
Type* ConstructAt(Type* ptr, Arguments&&... arguments) noexcept(kIsNothrowConstructible<Type, Arguments&&...>) {
  ASSERT(ptr != nullptr, "ptr must be a valid pointer");

  return new (ptr) Type(::std::forward<Arguments>(arguments)...);
}

template <typename Type>
void DestroyAt(Type* object) noexcept {
  if (object != nullptr) {
    object->~Type();
  }
}

}  // namespace crutch