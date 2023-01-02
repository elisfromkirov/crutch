#ifndef UTILITY_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename... ArgTypes>
void ConstructAt(Type* place, ArgTypes&&... args) {
  new (place) Type(::std::forward<ArgTypes>(args)...);
}

template <typename Type>
void DestroyAt(Type* place) noexcept {
  place->~Type();
}

}  // namespace crutch