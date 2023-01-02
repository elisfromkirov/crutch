#ifndef VECTOR_BASE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type, typename Allocator>
VectorBase<Type, Allocator>::VectorBase(SizeType capacity,
                                        const Allocator& allocator)
    : Allocator{allocator},
      Buffer<Type>{this->Allocate(capacity), 0, capacity} {
}

template <typename Type, typename Allocator>
VectorBase<Type, Allocator>::VectorBase(const VectorBase& other)
    : Allocator{other},
      Buffer<Type>{this->Allocate(other.capacity_), 0, other.capacity_} {
  this->CopyToEnd(other);
}

template <typename Type, typename Allocator>
VectorBase<Type, Allocator>& VectorBase<Type, Allocator>::operator=(
    const VectorBase& other) {
    if (this != &other) {
      VectorBase<Type, Allocator> temp{other};
      this->Swap(temp);
    }
    return *this;
}

template <typename Type, typename Allocator>
VectorBase<Type, Allocator>::VectorBase(VectorBase&& other) noexcept
    : Allocator{::std::move(other)},
      Buffer<Type>{other.data_, other.size_, other.capacity_} {
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename Type, typename Allocator>
VectorBase<Type, Allocator>& VectorBase<Type, Allocator>::operator=(
    VectorBase&& other) noexcept {
    if (this != &other) {
      VectorBase<Type, Allocator> temp{::std::move(other)};
      this->Swap(temp);
    }
    return *this;
}

template <typename Type, typename Allocator>
VectorBase<Type, Allocator>::~VectorBase() noexcept {
  this->DestroyAll();
  this->Deallocate(this->data_);
}

template <typename Type, typename Allocator>
void VectorBase<Type, Allocator>::Swap(VectorBase& other) noexcept {
  ::std::swap(static_cast<Allocator>(*this), static_cast<Allocator>(other));
  ::std::swap(this->data_, other.data_);
  ::std::swap(this->size_, other.size_);
  ::std::swap(this->capacity_, other.capacity_);
}

}  // namespace detail

}  // namespace crutch