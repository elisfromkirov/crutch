#pragma once

#include <wheel/core/core.hpp>

#include <wheel/iterator/const_ptr.hpp>
#include <wheel/iterator/ptr.hpp>

namespace wheel {

template <typename Type, SizeType size>
class Array {
 public:
  using Iterator = Ptr<Type>;

  using ConstIterator = ConstPtr<Type>;

 public:
  Iterator Begin() noexcept;

  Iterator End() noexcept;

  ConstIterator ConstBegin() const noexcept;

  ConstIterator ConstEnd() const noexcept;

  Type& operator[](SizeType index) noexcept;

  const Type& operator[](SizeType index) const noexcept;

  Type& At(SizeType index) noexcept;

  const Type& At(SizeType index) const noexcept;

  Type* Data() noexcept;

  const Type* Data() const noexcept;

  [[nodiscard]]
  SizeType Size() const noexcept;

 private:
  alignas(alignof(Type)) Byte data_[size * sizeof(Type)];
};

}  // namespace wheel

#define ARRAY_IMPL
#include <wheel/array/array.ipp>
#undef ARRAY_IMPL