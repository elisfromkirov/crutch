#pragma once

#include <crutch/memory/address.hpp>

#include <crutch/list/detail/list_node.hpp>

namespace crutch {

template <typename Type>
class ListConstIterator {
 public:
  explicit ListConstIterator(const detail::ListNode<Type>* node = nullptr) noexcept;

  bool operator==(const ListConstIterator& other) const noexcept;

  bool operator!=(const ListConstIterator& other) const noexcept;

  ListConstIterator& operator++() noexcept;

  const ListConstIterator operator++(int) noexcept;

  ListConstIterator& operator--() noexcept;

  const ListConstIterator operator--(int) noexcept;

  const Type& operator*() const noexcept;

  const Type* operator->() const noexcept;

 private:
  const detail::ListNode<Type>* node_;
};

}  // namespace crutch

#define LIST_CONST_ITERATOR_IMPL
#include <crutch/list/list_const_iterator.ipp>
#undef LIST_CONST_ITERATOR_IMPL