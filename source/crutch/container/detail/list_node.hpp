#pragma once

#include <crutch/concept/allocator_for.hpp>
#include <crutch/concept/constructible.hpp>

#include <crutch/core/assert.hpp>

namespace crutch {

namespace detail {

template <typename Type, typename Allocator>
class ListNode {
  using ListNodePointer = typename Allocator::Pointer;
  using ListNodeConstPointer = typename Allocator::ConstPointer;

 public:
  template <typename... ArgTypes>
  explicit ListNode(ListNodePointer next, ListNodePointer prev, ArgTypes&&... args);

  [[nodiscard]]
  ListNodePointer Next() noexcept;

  [[nodiscard]]
  ListNodeConstPointer Next() const noexcept;

  [[nodiscard]]
  ListNodePointer Prev() noexcept;

  [[nodiscard]]
  ListNodeConstPointer Prev() const noexcept;

  [[nodiscard]]
  Type& Value() noexcept;

  [[nodiscard]]
  const Type& Value() const noexcept;

  void LinkAfter(ListNodePointer node) noexcept;

  void LinkBefore(ListNodePointer node) noexcept;

  void Unlink() noexcept;

 private:
  ListNodePointer next_;
  ListNodePointer prev_;
  Type value_;
};

}  // namespace detail

}  // namespace crutch

#define LIST_NODE_IMPL
#include <crutch/container/detail/list_node.ipp>
#undef LIST_NODE_IMPL