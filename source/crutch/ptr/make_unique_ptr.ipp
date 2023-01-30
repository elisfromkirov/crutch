#ifndef MAKE_UNIQUE_PTR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename... ArgTypes>
requires Constructible<Type, ArgTypes&&...>
UniquePtr<Type> MakeUniquePtr(ArgTypes&&... args) {
  auto pointer = Allocate(GetDefaultAllocator(), sizeof(Type));
  auto object = Construct<Type>(::std::move(pointer), ::std::forward<ArgTypes>(args)...);
  return UniquePtr<Type>{object};
}

}  // namespace crutch