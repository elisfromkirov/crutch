#ifndef DEFAULT_DELETER_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type>
template <DerivedFrom<Type> DerivedType>
DefaultDeleter<Type>::DefaultDeleter(DefaultDeleter<DerivedType>&& other) noexcept {
}

template <typename Type>
void DefaultDeleter<Type>::operator()(Type* object) noexcept {
  auto ptr = Destroy(object, GetDefaultAllocator());
}

}  // namespace detail

}  // namespace crutch