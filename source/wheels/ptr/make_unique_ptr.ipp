#ifndef MAKE_UNIQUE_PTR_IMPL
#error Do not include this file directly
#endif

namespace wheels {

template <typename Type, typename... Arguments>
requires Constructible<Type, Arguments&&...>
UniquePtr<Type> MakeUniquePtr(Arguments&&... arguments) {
  auto ptr = Allocate<Type>(GetDefaultAllocator());
  auto object = Construct(::std::move(ptr), ::std::forward<Arguments>(arguments)...);
  return UniquePtr<Type>{object};
}

}  // namespace wheels