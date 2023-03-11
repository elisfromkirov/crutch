#pragma once

#include <wheels/concept/constructible.hpp>
#include <wheels/concept/copyable.hpp>
#include <wheels/concept/moveable.hpp>

#include <wheels/core/core.hpp>

#include <wheels/iterator/const_ptr.hpp>
#include <wheels/iterator/ptr.hpp>

#include <wheels/memory/allocator.hpp>
#include <wheels/memory/default.hpp>

#include <wheels/vector/detail/vector_base.hpp>

namespace wheels {

template <typename Type>
class Vector : private detail::VectorBase<Type> {
 public:
  static constexpr const SizeType kDefaultCapacity{8};

  static constexpr const float kDefaultGrowthFactor{1.5f};

 public:
  using Iterator = Ptr<Type>;

  using ConstIterator = ConstPtr<Type>;

 public:
  explicit Vector(SizeType capacity = kDefaultCapacity, IAllocator* allocator = GetDefaultAllocator());

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

  void Assign(const Vector& other) requires Copyable<Type>;

  void Assign(Vector&& other) noexcept requires Moveable<Type>;
};

}  // namespace wheels

#define VECTOR_IMPL
#include <wheels/vector/vector.ipp>
#undef VECTOR_IMPL