#pragma once

#include <crutch/allocator/core/allocator.hpp>
#include <crutch/allocator/core/default.hpp>

#include <crutch/container/list_const_iterator.hpp>
#include <crutch/container/list_iterator.hpp>

#include <crutch/container/detail/list_base.hpp>
#include <crutch/container/detail/list_node.hpp>

#include <crutch/core/concept/constructible.hpp>
#include <crutch/core/concept/copy_constructible.hpp>
#include <crutch/core/concept/move_constructible.hpp>

namespace crutch {

template <typename Type>
class List : detail::ListBase<Type> {
 public:
  using Iterator = ListIterator<Type>;

  using ConstIterator = ListConstIterator<Type>;

 public:
  explicit List(IAllocator* allocator = GetDefaultAllocator());

  Iterator Begin() noexcept;

  Iterator End() noexcept;

  ConstIterator ConstBegin() const noexcept;

  ConstIterator ConstEnd() const noexcept;

  Type& Front() noexcept;

  const Type& Front() const noexcept;

  Type& Back() noexcept;

  const Type& Back() const noexcept;

  [[nodiscard]]
  bool IsEmpty() const noexcept;

  void PushFront(const Type& value) requires CopyConstructible<Type>;

  void PushFront(Type&& value) noexcept requires MoveConstructible<Type>;

  template <typename... ArgTypes>
  requires Constructible<Type, ArgTypes...>
  void EmplaceFront(ArgTypes&&... args);

  void PushBack(const Type& value) requires CopyConstructible<Type>;

  void PushBack(Type&& value) noexcept requires MoveConstructible<Type>;

  template <typename... ArgTypes>
  requires Constructible<Type, ArgTypes...>
  void EmplaceBack(ArgTypes&&... args);

  void PopFront() noexcept;

  void PopBack() noexcept;
};

}  // namespace crutch

#define LIST_IMPL
#include <crutch/container/list/list.ipp>
#undef LIST_IMPL