#ifndef VECTOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type, typename Allocator>
Vector<Type, Allocator>::Vector()
    : detail::VectorBase<Type, Allocator>{kDefaultCapacity, Allocator()} {
}

template <typename Type, typename Allocator>
Type& Vector<Type, Allocator>::operator[](SizeType index) noexcept {
  ASSERT(index < this->size_, "Must be");

  return this->data_[index];
}

template <typename Type, typename Allocator>
const Type& Vector<Type, Allocator>::operator[](SizeType index) const noexcept {
  ASSERT(index < this->size_, "Must be");

  return this->data_[index];
}

template <typename Type, typename Allocator>
Type& Vector<Type, Allocator>::At(SizeType index) noexcept {
  ASSERT(index < this->size_, "Must be");

  return this->data_[index];
}

template <typename Type, typename Allocator>
const Type& Vector<Type, Allocator>::At(SizeType index) const noexcept {
  ASSERT(index < this->size_, "Must be");

  return this->data_[index];
}

template <typename Type, typename Allocator>
Type& Vector<Type, Allocator>::Back() noexcept {
  ASSERT(!IsEmpty(), "Must be");

  return this->data_[this->size_ - 1];
}

template <typename Type, typename Allocator>
const Type& Vector<Type, Allocator>::Back() const noexcept {
  ASSERT(!IsEmpty(), "Must be");

  return this->data_[this->size_ - 1];
}

template <typename Type, typename Allocator>
Type* Vector<Type, Allocator>::Data() noexcept {
  return this->data_;
}

template <typename Type, typename Allocator>
const Type* Vector<Type, Allocator>::Data() const noexcept {
  return this->data_;
}

template <typename Type, typename Allocator>
bool Vector<Type, Allocator>::IsEmpty() const noexcept {
  return this->size_ == 0;
}

template <typename Type, typename Allocator>
SizeType Vector<Type, Allocator>::Size() const noexcept {
  return this->size_;
}

template <typename Type, typename Allocator>
SizeType Vector<Type, Allocator>::Capacity() const noexcept {
  return this->capacity_;
}

template <typename Type, typename Allocator>
void Vector<Type, Allocator>::Reserve(SizeType capacity) {
  detail::VectorBase<Type, Allocator> temp{capacity};
  temp->MoveToEnd(::std::move(*this));
  this->Swap(temp);
}

template <typename Type, typename Allocator>
void Vector<Type, Allocator>::PushBack(const Type& value) {
  EmplaceBack(value);
}

template <typename Type, typename Allocator>
void Vector<Type, Allocator>::PushBack(Type&& value) {
  EmplaceBack(std::move(value));
}

template <typename Type, typename Allocator>
template <typename... ArgTypes>
void Vector<Type, Allocator>::EmplaceBack(ArgTypes&&... args) {
  if (this->size_ == this->capacity_) {
    Reserve(this->capacity_ * kCapacityGrowthFactor);
  }
  this->ConstructAtEnd(std::forward<ArgTypes>(args)...);
}

template <typename Type, typename Allocator>
void Vector<Type, Allocator>::PopBack() noexcept {
  ASSERT(!IsEmpty(), "Must be");

  this->DestroyAtEnd();
}

}  // namespace crutch