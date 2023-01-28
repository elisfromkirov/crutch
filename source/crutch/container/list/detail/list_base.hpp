#pragma once

#include <crutch/allocator/core/allocator.hpp>
#include <crutch/allocator/core/placement.hpp>

#include <crutch/core/concept/copy_constructible.hpp>

#include <crutch/container/list/detail/list_node.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class ListBase {
 public:
  explicit ListBase(IAllocator* allocator) noexcept;

  ListBase(const ListBase& other) requires CopyConstructible<Type>;
  ListBase& operator=(const ListBase& other) requires CopyConstructible<Type>;

  ListBase(ListBase&& other) noexcept;
  ListBase& operator=(ListBase&& other) requires CopyConstructible<Type>;

 protected:
  ~ListBase() noexcept;

  void Swap(ListBase& other) noexcept;

 protected:
  ListNode<Type>* head_;
  ListNode<Type>* tail_;
  IAllocator* allocator_;
};

}  // namespace detail

}  // namespace crutch

#define LIST_BASE_IMPL
#include "list_base.ipp"
#undef LIST_BASE_IMPL