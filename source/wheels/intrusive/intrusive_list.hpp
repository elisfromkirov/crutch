#pragma once

#include <wheels/intrusive/intrusive_node.hpp>

namespace wheels {

template <typename Type>
class IntrusiveList {
 public:
  IntrusiveNode<Type>* Begin() noexcept;

  IntrusiveNode<Type>* End() noexcept;

  [[nodiscard]]
  IntrusiveNode<Type>* Front() noexcept;

  [[nodiscard]]
  IntrusiveNode<Type>* Back() noexcept;

  [[nodiscard]]
  bool IsEmpty() const noexcept;

  void PushFront(IntrusiveNode<Type>* node) noexcept;

  void PushBack(IntrusiveNode<Type>* node) noexcept;

  void PopFront() noexcept;

  void PopBack() noexcept;

 private:
  IntrusiveNode<Type> node_;
};

}  // namespace wheels

#define LIST_IMPL
#include <wheels/intrusive/intrusive_list.ipp>
#undef LIST_IMPL