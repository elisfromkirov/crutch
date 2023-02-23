#ifndef PTR_IMPL
#include <wheels/iterator/ptr.hpp>
#endif

namespace wheels {

#ifndef ON_DEBUG

template <typename Type>
Ptr<Type>::Ptr(Type* ptr) noexcept
    : ptr_{ptr} {
}

#else

template <typename Type>
Ptr<Type>::Ptr() noexcept
    : ptr_{nullptr},
      begin_{nullptr},
      end_{nullptr} {
}

template <typename Type>
Ptr<Type>::Ptr(Type* ptr, Type* begin, Type* end) noexcept
    : ptr_{ptr},
      begin_{begin},
      end_{end} {
}

#endif

template <typename Type>
Ptr<Type>& Ptr<Type>::operator+=(SizeType offset) noexcept {
  ASSERT(IsValid(), "iterator is invalid");
  ptr_ += offset;
  ASSERT(IsValid(), "iterator is invalid");
  return *this;
}

template <typename Type>
Ptr<Type>& Ptr<Type>::operator-=(SizeType offset) noexcept {
  ASSERT(IsValid(), "iterator is invalid");
  ptr_ -= offset;
  ASSERT(IsValid(), "iterator is invalid");
  return *this;
}

template <typename Type>
Ptr<Type>& Ptr<Type>::operator++() noexcept {
  ASSERT(IsValid(), "iterator is invalid");
  ++ptr_;
  ASSERT(IsValid(), "iterator is invalid");
  return *this;
}

template <typename Type>
const Ptr<Type> Ptr<Type>::operator++(int) noexcept {
  Ptr<Type> tmp{*this};
  ++(*this);
  return tmp;
}

template <typename Type>
Ptr<Type>& Ptr<Type>::operator--() noexcept {
  ASSERT(IsValid(), "iterator is invalid");
  --ptr_;
  ASSERT(IsValid(), "iterator is invalid");
  return *this;
}

template <typename Type>
const Ptr<Type> Ptr<Type>::operator--(int) noexcept {
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
  return ptr_;
}

template <typename Type>
bool Ptr<Type>::IsValid() const noexcept {
#if !defined(ON_DEBUG)
  return ptr_ != nullptr;
#else
  return ptr_ != nullptr && begin_ <= ptr_ && ptr_ <= end_;
#endif
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