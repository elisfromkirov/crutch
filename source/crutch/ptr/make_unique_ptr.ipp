#ifndef MAKE_UNIQUE_PTR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes&&...>
UniquePtr<Type> MakeUniquePtr(ArgTypes&&... args) {
  auto ptr = Allocate<Type>(GetDefaultAllocator());
  auto object = Construct(::std::move(ptr), ::std::forward<ArgTypes>(args)...);
  return UniquePtr<Type>{object};
}

}  // namespace crutch