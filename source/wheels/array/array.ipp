#ifndef ARRAY_IMPL
#error Do not include this file directly
#endif

namespace wheels {

template <typename Type, SizeType size>
typename Array<Type, size>::Iterator Array<Type, size>::Begin() noexcept {
  return Iterator{data_};
}

template <typename Type, SizeType size>
typename Array<Type, size>::Iterator Array<Type, size>::End() noexcept {
  return Iterator{data_ + size};
}

template <typename Type, SizeType size>
typename Array<Type, size>::ConstIterator Array<Type, size>::ConstBegin() const noexcept {
  return ConstIterator{data_};
}

template <typename Type, SizeType size>
typename Array<Type, size>::ConstIterator Array<Type, size>::ConstEnd() const noexcept {
  return ConstIterator{data_ + size};
}

template <typename Type, SizeType size>
Type& Array<Type, size>::operator[](SizeType index) noexcept {
  ASSERT(index < size, "index must be less than array's size");

  return Data()[index];
}

template <typename Type, SizeType size>
const Type& Array<Type, size>::operator[](SizeType index) const noexcept {
  ASSERT(index < size, "index must be less than array's size");

  return Data()[index];
}

template <typename Type, SizeType size>
Type& Array<Type, size>::At(SizeType index) noexcept {
  ASSERT(index < size, "index must be less than array's size");

  return Data()[index];
}

template <typename Type, SizeType size>
const Type& Array<Type, size>::At(SizeType index) const noexcept {
  ASSERT(index < size, "index must be less than array's size");

  return Data()[index];
}

template <typename Type, SizeType size>
Type* Array<Type, size>::Data() noexcept {
  return reinterpret_cast<Type*>(data_);
}

template <typename Type, SizeType size>
const Type* Array<Type, size>::Data() const noexcept {
  return reinterpret_cast<Type*>(data_);
}

template <typename Type, SizeType size>
SizeType Array<Type, size>::Size() const noexcept {
  return size;
}

}  // namespace wheels