#ifndef UNIQUE_PTR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Type, Deleter>
UniquePtr<Type, Deleter>::UniquePtr(Type* pointer) noexcept
    : detail::UniquePtrBase<Type, Deleter>{pointer} {
}

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Type, Deleter>
Type* UniquePtr<Type, Deleter>::Get() const noexcept {
  return this->pointer_;
}

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Type, Deleter>
Type& UniquePtr<Type, Deleter>::operator*() const noexcept {
  return *(this->pointer_);
}

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Type, Deleter>
Type* UniquePtr<Type, Deleter>::operator->() const noexcept {
  return this->pointer_;
}

}  // namespace crutch