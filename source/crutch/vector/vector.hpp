#pragma once

#include <crutch/concept/constructible.hpp>
#include <crutch/concept/copyable.hpp>
#include <crutch/concept/moveable.hpp>

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/default.hpp>

#include <crutch/vector/detail/vector_base.hpp>

namespace crutch {

template <typename Type>
class Vector : private detail::VectorBase<Type> {
 public:
  static constexpr SizeType default_capacity{8};

  static constexpr SizeType default_growth_factor{2};

 public:
  using Iterator = Type*;

  using ConstIterator = const Type*;

 public:
  explicit Vector(SizeType capacity = default_capacity, IAllocator* allocator = GetDefaultAllocator());

  Vector(const Vector& other);
  Vector& operator=(const Vector& other);

  Vector(Vector&& other) noexcept = default;
  Vector& operator=(Vector&& other) noexcept = default;

  Iterator Begin() noexcept;

  Iterator End() noexcept;

  ConstIterator ConstBegin() const noexcept;

  ConstIterator ConstEnd() const noexcept;

  Type& operator[](SizeType index) noexcept;

  const Type& operator[](SizeType index) const noexcept;

  Type& At(SizeType index) noexcept;

  const Type& At(SizeType index) const noexcept;

  Type& Back() noexcept;

  const Type& Back() const noexcept;

  Type* Data() noexcept;

  const Type* Data() const noexcept;

  [[nodiscard]]
  bool IsEmpty() const noexcept;

  [[nodiscard]]
  SizeType Size() const noexcept;

  [[nodiscard]]
  SizeType Capacity() const noexcept;

  void Reserve(SizeType capacity) requires Copyable<Type> && (!Moveable<Type>);

  void Reserve(SizeType capacity) requires Moveable<Type>;

  void PushBack(const Type& value) requires Copyable<Type>;

  void PushBack(Type&& value) requires Moveable<Type>;

  template <typename... Arguments>
  requires Constructible<Type, Arguments&&...>
  void EmplaceBack(Arguments&&... arguments);

  void PopBack() noexcept;

 private:
  void CopyToEnd(const Vector& other) requires Copyable<Type>;

  void MoveToEnd(Vector&& other) noexcept requires Moveable<Type>;
};

}  // namespace crutch

#define VECTOR_IMPL
#include <crutch/vector/vector.ipp>
#undef VECTOR_IMPL