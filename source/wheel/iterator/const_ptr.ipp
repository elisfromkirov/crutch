#ifndef CONST_PTR_IMPL
#include <wheel/iterator/ptr.hpp>
#endif

namespace wheel {

#ifndef ON_DEBUG

template <typename Type>
ConstPtr<Type>::ConstPtr(const Type* ptr) noexcept
    : ptr_{ptr} {
}

#else

template <typename Type>
ConstPtr<Type>::ConstPtr() noexcept
    : ptr_{nullptr},
      begin_{nullptr},
      end_{nullptr} {
}

template <typename Type>
ConstPtr<Type>::ConstPtr(const Type* ptr, const Type* begin, const Type* end) noexcept
    : ptr_{ptr},
      begin_{begin},
      end_{end} {
}

#endif

template <typename Type>
ConstPtr<Type>& ConstPtr<Type>::operator+=(SizeType offset) noexcept {
  ASSERT(IsValid(), "iterator is invalid");
  ptr_ += offset;
  ASSERT(IsValid(), "iterator is invalid");
  return *this;
}

template <typename Type>
ConstPtr<Type>& ConstPtr<Type>::operator-=(SizeType offset) noexcept {
  ASSERT(IsValid(), "iterator is invalid");
  ptr_ -= offset;
  ASSERT(IsValid(), "iterator is invalid");
  return *this;
}

template <typename Type>
ConstPtr<Type>& ConstPtr<Type>::operator++() noexcept {
  ASSERT(IsValid(), "iterator is invalid");
  ++ptr_;
  ASSERT(IsValid(), "iterator is invalid");
  return *this;
}

template <typename Type>
const ConstPtr<Type> ConstPtr<Type>::operator++(int) noexcept {
  ConstPtr<Type> tmp{*this};
  ++(*this);
  return tmp;
}

template <typename Type>
ConstPtr<Type>& ConstPtr<Type>::operator--() noexcept {
  ASSERT(IsValid(), "iterator is invalid");
  --ptr_;
  ASSERT(IsValid(), "iterator is invalid");
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
  return ptr_;
}

template <typename Type>
bool ConstPtr<Type>::IsValid() const noexcept {
#if !defined(ON_DEBUG)
  return ptr_ != nullptr;
#else
  return ptr_ != nullptr && begin_ <= ptr_ && ptr_ <= end_;
#endif
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

}  // namespace wheel