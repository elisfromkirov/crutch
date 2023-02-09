#ifndef UNIQUE_PTR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, DeleterFor<Type> Deleter>
UniquePtr<Type, Deleter>::UniquePtr(Type* pointer, const Deleter& deleter) noexcept
    : detail::UniquePtrBase<Type, Deleter>{pointer, deleter} {
}

template <typename Type, DeleterFor<Type> Deleter>
template <DerivedFrom<Type> DerivedType, DeleterFor<DerivedType> DerivedTypeDeleter>
UniquePtr<Type, Deleter>::UniquePtr(UniquePtr<DerivedType, DerivedTypeDeleter>&& other, const Deleter& deleter) noexcept
    : detail::UniquePtrBase<Type, Deleter>{other.Get(), deleter} {
  other.Release();
}

template <typename Type, DeleterFor<Type> Deleter>
Type& UniquePtr<Type, Deleter>::operator*() const noexcept {
  return *(this->pointer_);
}

template <typename Type, DeleterFor<Type> Deleter>
Type* UniquePtr<Type, Deleter>::operator->() const noexcept {
  return this->pointer_;
}

template <typename Type, DeleterFor<Type> Deleter>
Type* UniquePtr<Type, Deleter>::Get() const noexcept {
  return this->pointer_;
}

template <typename Type, DeleterFor<Type> Deleter>
void UniquePtr<Type, Deleter>::Release() noexcept {
  this->pointer_ = nullptr;
}

template <typename Type, DeleterFor<Type> Deleter>
void UniquePtr<Type, Deleter>::Swap(UniquePtr& other) noexcept {
  detail::UniquePtrBase<Type, Deleter>::Swap(other);
}

}  // namespace crutch