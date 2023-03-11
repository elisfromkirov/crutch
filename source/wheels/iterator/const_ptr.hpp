#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

template <typename Type>
class ConstPtr {
 public:
  explicit ConstPtr(const Type* ptr = nullptr) noexcept;

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
  const Type* ptr_;
};

template <typename Type>
bool operator==(ConstPtr<Type> lhs, ConstPtr<Type> rhs) noexcept;

template <typename Type>
bool operator!=(ConstPtr<Type> lhs, ConstPtr<Type> rhs) noexcept;

template <typename Type>
const ConstPtr<Type> operator+(ConstPtr<Type> ptr, SizeType offset) noexcept;

template <typename Type>
const ConstPtr<Type> operator-(ConstPtr<Type> ptr, SizeType offset) noexcept;

}  // namespace wheels

#define CONST_PTR_IMPL
#include <wheels/iterator/const_ptr.ipp>
#undef CONST_PTR_IMPL