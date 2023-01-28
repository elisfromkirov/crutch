#pragma once

#include <crutch/container/detail/list_node.hpp>

namespace crutch {

namespace detail {

template <typename Type, typename Allocator>
class ListIterator {
 private:
  using ListNodePointer = typename ListNode<Type, Allocator>::ListNodePointer;

 public:
  explicit ListIterator(ListNodePointer node) noexcept;

  bool operator==(const ListIterator& other) const noexcept;

  bool operator!=(const ListIterator& other) const noexcept;

  ListIterator& operator++() noexcept;

  const ListIterator operator++(int) noexcept;

  ListIterator& operator--() noexcept;

  const ListIterator operator--(int) noexcept;

  Type& operator*() const noexcept;

  Type* operator->() const noexcept;

 private:
  ListNodePointer node_;
};

}  // namespace crutch

}  // namespace crutch

#define LIST_ITERATOR_IMPL
#include <crutch/container/detail/list_iterator.ipp>
#undef LIST_ITERATOR_IMPL