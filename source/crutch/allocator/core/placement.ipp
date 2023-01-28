#ifndef PLACEMENT_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes...>
void ConstructAt(RawPtr place, ArgTypes&&... args) {
  new (place.Get()) Type(::std::forward<ArgTypes>(args)...);
  place.Release();
}

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes...>
void ConstructAt(Type* place, ArgTypes&&... args) {
  new (place) Type(::std::forward<ArgTypes>(args)...);
}

template <typename Type>
void DestroyAt(Type* place) noexcept {
  place->~Type();
}

}  // namespace crutch