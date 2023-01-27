#ifndef UNIQUE_PTR_BASE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Deleter, Type>
UniquePtrBase<Type, Deleter>::UniquePtrBase(Type* pointer) noexcept
    : pointer_{pointer} {
}

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Deleter, Type>
UniquePtrBase<Type, Deleter>::UniquePtrBase(UniquePtrBase&& other) noexcept
    : pointer_{other.pointer_} {
  other.pointer_ = nullptr;
}

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Deleter, Type>
UniquePtrBase<Type, Deleter>& UniquePtrBase<Type, Deleter>::operator=(
    UniquePtrBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  UniquePtrBase<Type, Deleter> temp{::std::move(other)};
  Swap(temp);

  return *this;
}

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Deleter, Type>
UniquePtrBase<Type, Deleter>::~UniquePtrBase() noexcept {
  Deleter::Delete(pointer_);
}

template <typename Type, typename Deleter>
requires IsNotReference<Type> && DeleterFor<Deleter, Type>
void UniquePtrBase<Type, Deleter>::Swap(UniquePtrBase& other) noexcept {
  ::std::swap(pointer_, other.pointer_);
}

}  // namespace detail

}  // namespace crutch