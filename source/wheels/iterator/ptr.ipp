#ifndef PTR_IMPL
#include <wheels/iterator/ptr.hpp>
#endif

namespace wheels {

template <typename Type>
Ptr<Type>::Ptr(Type* ptr) noexcept
    : ptr_{ptr} {
}

template <typename Type>
Ptr<Type>& Ptr<Type>::operator+=(SizeType offset) noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  ptr_ += offset;
  return *this;
}

template <typename Type>
Ptr<Type>& Ptr<Type>::operator-=(SizeType offset) noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  ptr_ -= offset;
  return *this;
}

template <typename Type>
Ptr<Type>& Ptr<Type>::operator++() noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  ++ptr_;
  return *this;
}

template <typename Type>
const Ptr<Type> Ptr<Type>::operator++(int) noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  Ptr<Type> tmp{*this};
  ++(*this);
  return tmp;
}

template <typename Type>
Ptr<Type>& Ptr<Type>::operator--() noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  --ptr_;
  return *this;
}

template <typename Type>
const Ptr<Type> Ptr<Type>::operator--(int) noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  Ptr<Type> tmp{*this};
  --(*this);
  return tmp;
}

template <typename Type>
Type& Ptr<Type>::operator*() noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  return *ptr_;
}

template <typename Type>
Type* Ptr<Type>::operator->() noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  return ptr_;
}

template <typename Type>
Type* Ptr<Type>::Base() noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  return ptr_;
}

template <typename Type>
bool Ptr<Type>::IsValid() const noexcept {
  return ptr_ != nullptr;
}

template <typename Type>
bool operator==(Ptr<Type> lhs, Ptr<Type> rhs) noexcept {
  return lhs.Base() == rhs.Base();
}

template <typename Type>
bool operator!=(Ptr<Type> lhs, Ptr<Type> rhs) noexcept {
  return lhs.Base() != rhs.Base();
}

template <typename Type>
const Ptr<Type> operator+(Ptr<Type> ptr, SizeType offset) noexcept {
  return Ptr<Type>{ptr += offset};
}

template <typename Type>
const Ptr<Type> operator-(Ptr<Type> ptr, SizeType offset) noexcept {
  return Ptr<Type>{ptr -= offset};
}

}  // namespace wheels