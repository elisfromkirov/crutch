#ifndef PLACEMENT_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes&&...>
Type* Construct(RawPtr pointer, ArgTypes&&... args) {
  auto object = new (pointer.Get()) Type(::std::forward<ArgTypes>(args)...);
  pointer.Release();
  return object;
}

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes&&...>
void ConstructAt(Type* place, ArgTypes&&... args) {
  new (place) Type(::std::forward<ArgTypes>(args)...);
}

template <typename Type>
void DestroyAt(Type* place) noexcept {
  place->~Type();
}

}  // namespace crutch