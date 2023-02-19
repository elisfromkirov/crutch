#ifndef VECTOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type>
Vector<Type>::Vector(SizeType capacity, IAllocator* allocator)
    : detail::VectorBase<Type>{capacity, allocator} {
}

template <typename Type>
Vector<Type>::Vector(const Vector& other)
    : detail::VectorBase<Type>{other.capacity_, other.allocator_} {
  CopyToEnd(other);
}

template <typename Type>
Vector<Type>& Vector<Type>::operator=(const Vector& other) {
  if (this == &other) {
    return *this;
  }

  Vector<Type> tmp{other};
  this->Swap(tmp);

  return *this;
}

template <typename Type>
typename Vector<Type>::Iterator Vector<Type>::Begin() noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

#ifndef ON_DEBUG
  return Iterator{this->data_};
#else
  return Iterator{this->data_, this->data_, this->data_ + this->size_};
#endif
}

template <typename Type>
typename Vector<Type>::Iterator Vector<Type>::End() noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

#ifndef ON_DEBUG
  return Iterator{this->data_ + this->size_};
#else
  return Iterator{this->data_ + this->size_, this->data_, this->data_ + this->size_};
#endif
}

template <typename Type>
typename Vector<Type>::ConstIterator Vector<Type>::ConstBegin() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

#ifndef ON_DEBUG
  return ConstIterator{this->data_};
#else
  return ConstIterator{this->data_, this->data_, this->data_ + this->size_};
#endif
}

template <typename Type>
typename Vector<Type>::ConstIterator Vector<Type>::ConstEnd() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

#ifndef ON_DEBUG
  return ConstIterator{this->data_ + this->size_};
#else
  return ConstIterator{this->data_ + this->size_, this->data_, this->data_ + this->size_};
#endif
}

template <typename Type>
Type& Vector<Type>::operator[](SizeType index) noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(index < this->size_, "index must be less than vector's size");

  return this->data_[index];
}

template <typename Type>
const Type& Vector<Type>::operator[](SizeType index) const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(index < this->size_, "index must be less than vector's size");

  return this->data_[index];
}

template <typename Type>
Type& Vector<Type>::At(SizeType index) noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(index < this->size_, "index must be less than vector's size");

  return this->data_[index];
}

template <typename Type>
const Type& Vector<Type>::At(SizeType index) const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(index < this->size_, "index must be less than vector's size");

  return this->data_[index];
}

template <typename Type>
Type& Vector<Type>::Back() noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(this->size_ != 0, "vector must not be empty");

  return this->data_[this->size_ - 1];
}

template <typename Type>
const Type& Vector<Type>::Back() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(this->size_ != 0, "vector must not be empty");

  return this->data_[this->size_ - 1];
}

template <typename Type>
Type* Vector<Type>::Data() noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->data_;
}

template <typename Type>
const Type* Vector<Type>::Data() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->data_;
}

template <typename Type>
bool Vector<Type>::IsEmpty() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->size_ == 0;
}

template <typename Type>
SizeType Vector<Type>::Size() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->size_;
}

template <typename Type>
SizeType Vector<Type>::Capacity() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->capacity_;
}

template <typename Type>
void Vector<Type>::Reserve(SizeType capacity) requires Copyable<Type> && (!Moveable<Type>) {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(this->capacity_ < capacity, "capacity must be greater than current vector's capacity");

  Vector<Type> tmp{capacity, this->allocator_};
  tmp.CopyToEnd(*this);
  this->Swap(tmp);
}

template <typename Type>
void Vector<Type>::Reserve(SizeType capacity) requires Moveable<Type> {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(this->capacity_ < capacity, "capacity must be greater than current vector's capacity");

  Vector<Type> tmp{capacity, this->allocator_};
  tmp.MoveToEnd(::std::move(*this));
  this->Swap(tmp);
}

template <typename Type>
void Vector<Type>::PushBack(const Type& value) requires Copyable<Type> {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  EmplaceBack(value);
}

template <typename Type>
void Vector<Type>::PushBack(Type&& value) requires Moveable<Type> {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  EmplaceBack(::std::move(value));
}

template <typename Type>
template <typename... Arguments>
requires Constructible<Type, Arguments&&...>
void Vector<Type>::EmplaceBack(Arguments&&... arguments) {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  if (this->size_ == this->capacity_) {
    Reserve(static_cast<SizeType>(static_cast<float>(this->capacity_) * kDefaultGrowthFactor));
  }
  this->ConstructAtEnd(::std::forward<Arguments>(arguments)...);
}

template <typename Type>
void Vector<Type>::PopBack() noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(this->size_ != 0, "vector must not be empty");

  this->DestroyAtEnd();
}

template <typename Type>
void Vector<Type>::CopyToEnd(const Vector& other) requires Copyable<Type> {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  for (SizeType i = 0; i < other.size_; ++i) {
    this->ConstructAtEnd(other.data_[i]);
  }
}

template <typename Type>
void Vector<Type>::MoveToEnd(Vector&& other) noexcept requires Moveable<Type> {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  for (SizeType i = 0; i < other.size_; ++i) {
    this->ConstructAtEnd(::std::move(other.data_[i]));
  }
}


}  // namespace crutch