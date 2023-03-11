#ifndef CONST_PTR_IMPL
#include <wheels/iterator/ptr.hpp>
#endif

namespace wheels {

template <typename Type>
ConstPtr<Type>::ConstPtr(const Type* ptr) noexcept
    : ptr_{ptr} {
}

template <typename Type>
ConstPtr<Type>& ConstPtr<Type>::operator+=(SizeType offset) noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  ptr_ += offset;
  return *this;
}

template <typename Type>
ConstPtr<Type>& ConstPtr<Type>::operator-=(SizeType offset) noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  ptr_ -= offset;
  return *this;
}

template <typename Type>
ConstPtr<Type>& ConstPtr<Type>::operator++() noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  ++ptr_;
  return *this;
}

template <typename Type>
const ConstPtr<Type> ConstPtr<Type>::operator++(int) noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  ConstPtr<Type> tmp{*this};
  ++(*this);
  return tmp;
}

template <typename Type>
ConstPtr<Type>& ConstPtr<Type>::operator--() noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  --ptr_;
  return *this;
}

template <typename Type>
const ConstPtr<Type> ConstPtr<Type>::operator--(int) noexcept {
  ConstPtr<Type> tmp{*this};
  --(*this);
  return tmp;
}

template <typename Type>
const Type& ConstPtr<Type>::operator*() const noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  return *ptr_;
}

template <typename Type>
const Type* ConstPtr<Type>::operator->() const noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  return ptr_;
}

template <typename Type>
const Type* ConstPtr<Type>::Base() noexcept {
  ASSERT(IsValid(), "iterator is invalid");

  return ptr_;
}

template <typename Type>
bool ConstPtr<Type>::IsValid() const noexcept {
  return ptr_ != nullptr;
}

template <typename Type>
bool operator==(ConstPtr<Type> lhs, ConstPtr<Type> rhs) noexcept {
  return lhs.Base() == rhs.Base();
}

template <typename Type>
bool operator!=(ConstPtr<Type> lhs, ConstPtr<Type> rhs) noexcept {
  return lhs.Base() != rhs.Base();
}

template <typename Type>
const ConstPtr<Type> operator+(ConstPtr<Type> ptr, SizeType offset) noexcept {
  return ConstPtr<Type>{ptr += offset};
}

template <typename Type>
const ConstPtr<Type> operator-(ConstPtr<Type> ptr, SizeType offset) noexcept {
  return ConstPtr<Type>{ptr -= offset};
}

}  // namespace wheels