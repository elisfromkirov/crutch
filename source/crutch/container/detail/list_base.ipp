#ifndef LIST_BASE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type, AllocatorFor<ListNode<Type>> Allocator>
ListBase<Type, Allocator>::ListBase() noexcept
    : head_{nullptr},
      tail_{nullptr} {
}

template <typename Type, AllocatorFor<ListNode<Type>> Allocator>
ListBase<Type, Allocator>::ListBase(const ListBase& other) requires CopyConstructible<Type>
    : head_{nullptr},
      tail_{nullptr} {
  ///
}

template <typename Type, AllocatorFor<ListNode<Type>> Allocator>
ListBase<Type, Allocator>& ListBase<Type, Allocator>::operator=(
    const ListBase& other) requires CopyConstructible<Type> {
  if (this == &other) {
    return *this;
  }

  ListBase<Type, Allocator> temp{::std::move(other)};
  Swap(temp);

  return *this;
}

template <typename Type, AllocatorFor<ListNode<Type>> Allocator>
ListBase<Type, Allocator>::ListBase(ListBase&& other) noexcept
    : head_{other.head_},
      tail_{other.tail_} {
  other.head_ = nullptr;
  other.tail_ = nullptr;
}

template <typename Type, AllocatorFor<ListNode<Type>> Allocator>
ListBase<Type, Allocator>& ListBase<Type, Allocator>::operator=(ListBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  ListBase<Type, Allocator> temp{::std::move(other)};
  Swap(temp);

  return *this;
}

template <typename Type, AllocatorFor<ListNode<Type>> Allocator>
ListBase<Type, Allocator>::~ListBase() noexcept {
  ListNode<Type>* curr_node = head_;
  while (curr_node != nullptr) {
    ListNode<Type>* next_node = curr_node->Next();
    Allocator::Deallocate(curr_node);
    curr_node = next_node;
  }
}

template <typename Type, AllocatorFor<ListNode<Type>> Allocator>
void ListBase<Type, Allocator>::Swap(ListBase& other) noexcept {
  ::std::swap(head_, other.head_);
  ::std::swap(tail_, other.tail_);
}

}  // namespace detail

}  // namespace crutch