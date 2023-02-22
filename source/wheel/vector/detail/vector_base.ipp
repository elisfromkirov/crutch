#ifndef VECTOR_BASE_IMPL
#error Do not include this file directly
#endif

namespace wheel {

namespace detail {

template <typename Type>
VectorBase<Type>::VectorBase(SizeType capacity, IAllocator* allocator)
    : data_{static_cast<Type*>(allocator->Allocate(capacity * sizeof(Type), alignof(Type)))},
      size_{0},
      capacity_{capacity},
      allocator_{allocator} {
}

template <typename Type>
VectorBase<Type>::VectorBase(VectorBase&& other) noexcept
    : data_{other.data_},
      size_{other.size_},
      capacity_{other.capacity_},
      allocator_{other.allocator_} {
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename Type>
VectorBase<Type>& VectorBase<Type>::operator=(VectorBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  VectorBase<Type> temp{::std::move(other)};
  Swap(temp);

  return *this;
}

template <typename Type>
VectorBase<Type>::~VectorBase() noexcept {
  while (size_ != 0) {
    DestroyAtEnd();
  }
  allocator_->Deallocate(data_, capacity_ * sizeof(Type), alignof(Type));
}

template <typename Type>
void VectorBase<Type>::Swap(VectorBase& other) noexcept {
  ::std::swap(data_, other.data_);
  ::std::swap(size_, other.size_);
  ::std::swap(capacity_, other.capacity_);
  ::std::swap(allocator_, other.allocator_);
}

template <typename Type>
template <typename... Arguments>
requires Constructible<Type, Arguments&&...>
void VectorBase<Type>::ConstructAtEnd(Arguments&&... arguments) {
  ASSERT(data_ == nullptr, "vector is invalid");
  ASSERT(size_ < capacity_, "vector size must be less than capacity");

  ConstructAt(data_ + size_, ::std::forward<Arguments>(arguments)...);
  size_++;
}

template <typename Type>
void VectorBase<Type>::DestroyAtEnd() noexcept {
  ASSERT(data_ == nullptr, "vector is invalid");
  ASSERT(0 < size_, "vector size must be greater than zero");

  size_--;
  DestroyAt(data_ + size_);
}

}  // namespace detail

}  // namespace wheel