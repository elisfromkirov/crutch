#pragma once

#include <crutch/container/detail/list_node.hpp>

namespace crutch {

namespace detail {

template <typename Type, typename Allocator>
class ListConstIterator {
 private:
  using ListNodeConstPointer = typename ListNode<Type, Allocator>::ListNodeConstPointer;

 public:
  explicit ListConstIterator(ListNodeConstPointer node) noexcept;

  bool operator==(const ListConstIterator& other) const noexcept;

  bool operator!=(const ListConstIterator& other) const noexcept;

  ListConstIterator& operator++() noexcept;

  const ListConstIterator operator++(int) noexcept;

  ListConstIterator& operator--() noexcept;

  const ListConstIterator operator--(int) noexcept;

  const Type& operator*() const noexcept;

  const Type* operator->() const noexcept;

 private:
  ListNodeConstPointer node_;
};

}  // namespace crutch

}  // namespace crutch

#define LIST_CONST_ITERATOR_IMPL
#include <crutch/container/detail/list_const_iterator.ipp>
#undef LIST_CONST_ITERATOR_IMPL