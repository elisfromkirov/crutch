#ifndef VECTOR_BASE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type>
Type* Allocate(IAllocator* allocator, SizeType capacity) {
  return reinterpret_cast<Type*>(allocator->Allocate(capacity * sizeof(Type)));
}

}  // namespace detail

}  // namespace

namespace crutch {

namespace detail {

template <typename Type>
VectorBase<Type>::VectorBase(IAllocator* allocator, SizeType capacity)
    : Buffer<Type>{Allocate<Type>(allocator, capacity), 0, capacity},
      allocator_{allocator} {
}

template <typename Type>
VectorBase<Type>::VectorBase(const VectorBase& other) requires CopyConstructible<Type>
    : Buffer<Type>{Allocate<Type>(other.allocator_, other.capacity_), 0, other.capacity_},
      allocator_{other.allocator_} {
  this->CopyToEnd(other);
}

template <typename Type>
VectorBase<Type>& VectorBase<Type>::operator=(const VectorBase& other) requires CopyConstructible<Type> {
  if (this == &other) {
    return *this;
  }

  VectorBase<Type> temp{other};
  Swap(temp);

  return *this;
}

template <typename Type>
VectorBase<Type>::VectorBase(VectorBase&& other) noexcept
    : Buffer<Type>{other.data_, other.size_, other.capacity_},
      allocator_{other.allocator_} {
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename Type>
VectorBase<Type>& VectorBase<Type>::operator=(VectorBase&& other) {
  if (this == &other) {
    return *this;
  }

  if (allocator_->IsEqual(other.allocator_)) {
    VectorBase<Type> temp{::std::move(other)};
    Swap(temp);
  } else {
    VectorBase<Type> temp{other};
    Swap(temp);
  }

  return *this;
}

template <typename Type>
VectorBase<Type>::~VectorBase() noexcept {
  if (this->data_ != nullptr) {
    this->DestroyAll();
    allocator_->Deallocate(reinterpret_cast<Byte*>(this->data_), this->capacity_);
  }
}

template <typename Type>
void VectorBase<Type>::Swap(VectorBase& other) noexcept {
  ::std::swap(this->data_, other.data_);
  ::std::swap(this->size_, other.size_);
  ::std::swap(this->capacity_, other.capacity_);
  ::std::swap(allocator_, other.allocator_);
}

}  // namespace detail

}  // namespace crutch