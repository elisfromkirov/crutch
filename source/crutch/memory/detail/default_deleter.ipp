#ifndef DEFAULT_DELETER_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type>
void DefaultDeleter<Type>::Delete(Type* pointer) noexcept {
  delete pointer;
}

}  // namespace detail

}  // namespace crutch