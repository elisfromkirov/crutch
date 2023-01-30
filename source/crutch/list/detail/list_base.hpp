#pragma once

#include <crutch/concept/constructible.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/placement.hpp>

#include <crutch/list/detail/list_node.hpp>

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
#include <crutch/list/detail/list_base.ipp>
#undef LIST_BASE_IMPL