#pragma once

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Type>
class ConstPtr {
 public:
#ifndef ON_DEBUG
  explicit ConstPtr(const Type* ptr = nullptr) noexcept;
#else
  ConstPtr() noexcept;

  ConstPtr(const Type* ptr, const Type* begin, const Type* end) noexcept;
#endif

  ConstPtr& operator+=(SizeType offset) noexcept;
  ConstPtr& operator-=(SizeType offset) noexcept;

  ConstPtr& operator++() noexcept;
  const ConstPtr operator++(int) noexcept;

  ConstPtr& operator--() noexcept;
  const ConstPtr operator--(int) noexcept;

  const Type& operator*() const noexcept;

  const Type* operator->() const noexcept;

  const Type* Base() noexcept;

 private:
  [[nodiscard]]
  bool IsValid() const noexcept;

 private:
#ifndef ON_DEBUG
  const Type* ptr_;
#else
  const Type* ptr_;
  const Type* begin_;
  const Type* end_;
#endif
};

template <typename Type>
bool operator==(ConstPtr<Type> lhs, ConstPtr<Type> rhs) noexcept;

template <typename Type>
bool operator!=(ConstPtr<Type> lhs, ConstPtr<Type> rhs) noexcept;

template <typename Type>
const ConstPtr<Type> operator+(ConstPtr<Type> ptr, SizeType offset) noexcept;

template <typename Type>
const ConstPtr<Type> operator-(ConstPtr<Type> ptr, SizeType offset) noexcept;

}  // namespace crutch

#define CONST_PTR_IMPL
#include <crutch/iterator/const_ptr.ipp>
#undef CONST_PTR_IMPL