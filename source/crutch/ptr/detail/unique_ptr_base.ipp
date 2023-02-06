#ifndef UNIQUE_PTR_BASE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type, DeleterFor<Type> Deleter>
UniquePtrBase<Type, Deleter>::UniquePtrBase(Type* pointer, const Deleter& deleter) noexcept
    : Deleter{deleter},
      pointer_{pointer} {
}

template <typename Type, DeleterFor<Type> Deleter>
UniquePtrBase<Type, Deleter>::UniquePtrBase(UniquePtrBase&& other) noexcept
    : Deleter{GetDeleter()},
      pointer_{other.pointer_} {
  other.pointer_ = nullptr;
}

template <typename Type, DeleterFor<Type> Deleter>
UniquePtrBase<Type, Deleter>& UniquePtrBase<Type, Deleter>::operator=(UniquePtrBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  UniquePtrBase<Type, Deleter> temp{::std::move(other)};
  Swap(temp);

  return *this;
}

template <typename Type, DeleterFor<Type> Deleter>
UniquePtrBase<Type, Deleter>::~UniquePtrBase() noexcept {
  if (pointer_ != nullptr) {
    GetDeleter()(pointer_);
  }
}

template <typename Type, DeleterFor<Type> Deleter>
void UniquePtrBase<Type, Deleter>::Swap(UniquePtrBase& other) noexcept {
  ::std::swap(GetDeleter(), other.GetDeleter());
  ::std::swap(pointer_, other.pointer_);
}

template <typename Type, DeleterFor<Type> Deleter>
Deleter& UniquePtrBase<Type, Deleter>::GetDeleter() noexcept {
  return *this;
}

}  // namespace detail

}  // namespace crutch