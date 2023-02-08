#pragma once

#include <crutch/intrusive/intrusive_node.hpp>

namespace crutch {

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

}  // namespace crutch

#define LIST_IMPL
#include <crutch/intrusive/intrusive_list.ipp>
#undef LIST_IMPL