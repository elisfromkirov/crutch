#pragma once

#include <crutch/concept/constructible.hpp>

#include <crutch/core/core.hpp>

#include <crutch/list/list_const_iterator.hpp>
#include <crutch/list/list_iterator.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/default.hpp>

#include <crutch/list/detail/list_base.hpp>
#include <crutch/list/detail/list_node.hpp>

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

  void PushFront(Type&& value) requires MoveConstructible<Type>;

  template <typename... ArgTypes>
  requires Constructible<Type, ArgTypes&&...>
  void EmplaceFront(ArgTypes&&... args);

  void PushBack(const Type& value) requires CopyConstructible<Type>;

  void PushBack(Type&& value) requires MoveConstructible<Type>;

  template <typename... ArgTypes>
  requires Constructible<Type, ArgTypes&&...>
  void EmplaceBack(ArgTypes&&... args);

  void PopFront() noexcept;

  void PopBack() noexcept;
};

}  // namespace crutch

#define LIST_IMPL
#include <crutch/list/list.ipp>
#undef LIST_IMPL