#ifndef LIST_NODE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type, typename Allocator>
template <typename... ArgTypes>
ListNode<Type, Allocator>::ListNode(ListNodePointer next, ListNodePointer prev, ArgTypes&&... args)
    : next_{next},
      prev_{prev},
      value_{::std::forward<ArgTypes>(args)...} {
}

template <typename Type, typename Allocator>
typename ListNode<Type, Allocator>::ListNodePointer ListNode<Type, Allocator>::Next() noexcept {
  return next_;
}

template <typename Type, typename Allocator>
typename ListNode<Type, Allocator>::ListNodeConstPointer ListNode<Type, Allocator>::Next()
    const noexcept {
  return next_;
}

template <typename Type, typename Allocator>
typename ListNode<Type, Allocator>::ListNodePointer ListNode<Type, Allocator>::Prev() noexcept {
  return prev_;
}

template <typename Type, typename Allocator>
typename ListNode<Type, Allocator>::ListNodeConstPointer ListNode<Type, Allocator>::Prev()
    const noexcept {
  return prev_;
}

template <typename Type, typename Allocator>
Type& ListNode<Type, Allocator>::Value() noexcept {
  return value_;
}

template <typename Type, typename Allocator>
const Type& ListNode<Type, Allocator>::Value() const noexcept {
  return value_;
}

template <typename Type, typename Allocator>
void ListNode<Type, Allocator>::LinkAfter(ListNodePointer node) noexcept {
  ASSERT(node != nullptr, "node must be a valid pointer");

  if (next_ != nullptr) {
    next_->prev_ = node;
  }
  node->next_ = next_;
  next_ = node;
  node->prev_ = this;
}

template <typename Type, typename Allocator>
void ListNode<Type, Allocator>::LinkBefore(ListNodePointer node) noexcept {
  ASSERT(node != nullptr, "node must be a valid pointer");

  if (prev_ != nullptr) {
    prev_->next_ = node;
  }
  node->prev_ = prev_;
  prev_ = node;
  node->next_ = this;
}

template <typename Type, typename Allocator>
void ListNode<Type, Allocator>::Unlink() noexcept {
  if (next_ != nullptr) {
    next_->prev_ = prev_;
  }
  if (prev_ != nullptr) {
    prev_->next_ = next_;
  }
  next_ = nullptr;
  prev_ = nullptr;
}

}  // namespace detail

}  // namespace crutch