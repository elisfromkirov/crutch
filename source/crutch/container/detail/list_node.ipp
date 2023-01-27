#ifndef LIST_NODE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type>
template <typename... ArgTypes>
requires Constructible<Type, ArgTypes...>
ListNode<Type>::ListNode(ListNode* next, ListNode* prev, ArgTypes&&... args)
    : next_{next},
      prev_{prev},
      value_{::std::forward<ArgTypes>(args)...} {
}

template <typename Type>
ListNode<Type>* ListNode<Type>::Next() noexcept {
  return next_;
}

template <typename Type>
const ListNode<Type>* ListNode<Type>::Next() const noexcept {
  return next_;
}

template <typename Type>
ListNode<Type>* ListNode<Type>::Prev() noexcept {
  return prev_;
}

template <typename Type>
const ListNode<Type>* ListNode<Type>::Prev() const noexcept {
  return prev_;
}

template <typename Type>
Type& ListNode<Type>::Value() noexcept {
  return value_;
}

template <typename Type>
const Type& ListNode<Type>::Value() const noexcept {
  return value_;
}

template <typename Type>
void ListNode<Type>::LinkAfter(ListNode* node) noexcept {
  ASSERT(node != nullptr, "node must be a valid pointer");

  if (next_ != nullptr) {
    next_->prev_ = node;
  }
  node->next_ = next_;
  next_ = node;
  node->prev_ = this;
}

template <typename Type>
void ListNode<Type>::LinkBefore(ListNode* node) noexcept {
  ASSERT(node != nullptr, "node must be a valid pointer");

  if (prev_ != nullptr) {
    prev_->next_ = node;
  }
  node->prev_ = prev_;
  prev_ = node;
  node->next_ = this;
}

template <typename Type>
void ListNode<Type>::Unlink() noexcept {
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