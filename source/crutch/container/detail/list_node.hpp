#pragma once

#include <crutch/concept/constructible_from.hpp>

#include <crutch/core/assert.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class ListNode {
 public:
  template <typename... ArgTypes>
  requires ConstructibleFrom<Type, ArgTypes...>
  explicit ListNode(ListNode* next, ListNode* prev, ArgTypes&&... args);

  [[nodiscard]]
  ListNode* Next() noexcept;

  [[nodiscard]]
  const ListNode* Next() const noexcept;

  [[nodiscard]]
  ListNode* Prev() noexcept;

  [[nodiscard]]
  const ListNode* Prev() const noexcept;

  [[nodiscard]]
  Type& Value() noexcept;

  [[nodiscard]]
  const Type& Value() const noexcept;

  void LinkAfter(ListNode* node) noexcept;

  void LinkBefore(ListNode* node) noexcept;

  void Unlink() noexcept;

 private:
  ListNode* next_;
  ListNode* prev_;
  Type value_;
};

}  // namespace detail

}  // namespace crutch

#define LIST_NODE_IMPL
#include <crutch/container/detail/list_node.ipp>
#undef LIST_NODE_IMPL