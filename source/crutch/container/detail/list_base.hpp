#pragma once

#include <crutch/concept/allocator_for.hpp>
#include <crutch/concept/copy_constructible.hpp>

#include <crutch/container/detail/list_node.hpp>

namespace crutch {

namespace detail {

template <typename Type, AllocatorFor<ListNode<Type>> Allocator>
class ListBase {
 public:
  ListBase() noexcept;

  ListBase(const ListBase& other) requires CopyConstructible<Type>;
  ListBase& operator=(const ListBase& other) requires CopyConstructible<Type>;

  ListBase(ListBase&& other) noexcept;
  ListBase& operator=(ListBase&& other) noexcept;

 protected:
  ~ListBase() noexcept;

  void Swap(ListBase& other) noexcept;

 protected:
  ListNode<Type>* head_;
  ListNode<Type>* tail_;
};

}  // namespace detail

}  // namespace crutch

#define LIST_BASE_IMPL
#include <crutch/container/detail/list_base.ipp>
#undef LIST_BASE_IMPL