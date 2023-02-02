#ifndef RAW_PTR_BASE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type>
RawPtrBase<Type>::RawPtrBase(Type* pointer, IAllocator* allocator) noexcept
    : pointer_{pointer},
      allocator_{allocator} {
}

template <typename Type>
RawPtrBase<Type>::RawPtrBase(RawPtrBase&& other) noexcept
    : pointer_{other.pointer_},
      allocator_{other.allocator_} {
  other.pointer_ = nullptr;
}

template <typename Type>
RawPtrBase<Type>& RawPtrBase<Type>::operator=(RawPtrBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  RawPtrBase tmp{::std::move(other)};
  Swap(tmp);

  return *this;
}

template <typename Type>
RawPtrBase<Type>::~RawPtrBase() noexcept {
  allocator_->Deallocate(pointer_, sizeof(Type), alignof(Type));
}

template <typename Type>
void RawPtrBase<Type>::Swap(RawPtrBase<Type>& other) noexcept {
  ::std::swap(pointer_, other.pointer_);
  ::std::swap(allocator_, other.allocator_);
}

}  // namespace detail

}  // namespace crutch