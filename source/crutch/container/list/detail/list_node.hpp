#pragma once

#include <crutch/core/macro/assert.hpp>
#include <crutch/core/type/size.hpp>

#include <crutch/core/concept/constructible.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class ListNode {
 public:
  template <typename... ArgTypes>
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
#include <crutch/container/list/detail/list_node.ipp>
#undef LIST_NODE_IMPL