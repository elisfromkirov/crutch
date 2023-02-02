#ifndef UNIQUE_PTR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, DeleterFor<Type> Deleter>
UniquePtr<Type, Deleter>::UniquePtr(Type* pointer, Deleter&& deleter) noexcept
    : detail::UniquePtrBase<Type, Deleter>{pointer, ::std::move(deleter)} {
}

template <typename Type, DeleterFor<Type> Deleter>
template <DerivedFrom<Type> OtherType, DeleterFor<OtherType> OtherDeleter>
requires Constructible<Deleter, OtherDeleter&&>
UniquePtr<Type, Deleter>::UniquePtr(UniquePtr<OtherType, OtherDeleter>&& other) noexcept
    : detail::UniquePtrBase<Type, Deleter>{other.pointer_, Deleter{::std::move(other.GetDeleter())}} {
  other.pointer_ = nullptr;
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

}  // namespace crutch