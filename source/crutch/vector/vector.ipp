#ifndef VECTOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type>
Vector<Type>::Vector(IAllocator* allocator)
    : detail::VectorBase<Type>{allocator, default_capacity} {
}

template <typename Type>
typename Vector<Type>::Iterator Vector<Type>::Begin() noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->data_;
}

template <typename Type>
typename Vector<Type>::Iterator Vector<Type>::End() noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->data_ + this->size_;
}

template <typename Type>
typename Vector<Type>::ConstIterator Vector<Type>::ConstBegin() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->data_;
}

template <typename Type>
typename Vector<Type>::ConstIterator Vector<Type>::ConstEnd() const noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  return this->data_ + this->size_;
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
void Vector<Type>::Reserve(SizeType capacity) requires CopyConstructible<Type> && (!MoveConstructible<Type>) {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(this->capacity_ < capacity, "capacity must be greater than current vector's capacity");

  detail::VectorBase<Type> temp{this->allocator_, capacity};
  temp.CopyToEnd(*this);
  this->Swap(temp);
}

template <typename Type>
void Vector<Type>::Reserve(SizeType capacity) requires MoveConstructible<Type> {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(this->capacity_ < capacity, "capacity must be greater than current vector's capacity");

  detail::VectorBase<Type> temp{this->allocator_, capacity};
  temp.MoveToEnd(::std::move(*this));
  this->Swap(temp);
}


template <typename Type>
void Vector<Type>::PushBack(const Type& value) requires CopyConstructible<Type> {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  EmplaceBack(value);
}

template <typename Type>
void Vector<Type>::PushBack(Type&& value) requires MoveConstructible<Type> {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  EmplaceBack(::std::move(value));
}

template <typename Type>
template <typename... ArgTypes>
void Vector<Type>::EmplaceBack(ArgTypes&&... args) requires Constructible<Type, ArgTypes&&...> {
  ASSERT(this->data_ == nullptr, "vector is invalid");

  if (this->size_ == this->capacity_) {
    Reserve(this->capacity_ * default_growth_factor);
  }
  this->ConstructAtEnd(::std::forward<ArgTypes>(args)...);
}

template <typename Type>
void Vector<Type>::PopBack() noexcept {
  ASSERT(this->data_ == nullptr, "vector is invalid");
  ASSERT(this->size_ != 0, "vector must not be empty");

  this->DestroyAtEnd();
}

}  // namespace crutch