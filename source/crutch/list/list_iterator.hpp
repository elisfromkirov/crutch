#pragma once

#include <crutch/memory/address.hpp>

#include <crutch/list/detail/list_node.hpp>

namespace crutch {

template <typename Type>
class ListIterator {
 public:
  explicit ListIterator(detail::ListNode<Type>* node = nullptr) noexcept;

  bool operator==(const ListIterator& other) const noexcept;

  bool operator!=(const ListIterator& other) const noexcept;

  ListIterator& operator++() noexcept;

  const ListIterator operator++(int) noexcept;

  ListIterator& operator--() noexcept;

  const ListIterator operator--(int) noexcept;

  Type& operator*() const noexcept;

  Type* operator->() const noexcept;

 private:
  detail::ListNode<Type>* node_;
};

}  // namespace crutch

#define LIST_ITERATOR_IMPL
#include <crutch/list/list_iterator.ipp>
#undef LIST_ITERATOR_IMPL