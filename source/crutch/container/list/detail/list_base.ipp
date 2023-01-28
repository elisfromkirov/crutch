#ifndef LIST_BASE_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type>
ListBase<Type>::ListBase(IAllocator* allocator) noexcept
    : head_{nullptr},
      tail_{nullptr},
      allocator_{allocator} {
}

template <typename Type>
ListBase<Type>::ListBase(const ListBase& other) requires CopyConstructible<Type>
    : head_{nullptr},
      tail_{nullptr},
      allocator_{other.allocator_} {
  /// TODO: Implement me!
}

template <typename Type>
ListBase<Type>& ListBase<Type>::operator=(const ListBase& other) requires CopyConstructible<Type> {
  if (this == &other) {
    return *this;
  }

  ListBase<Type> temp{other};
  Swap(temp);

  return *this;
}

template <typename Type>
ListBase<Type>::ListBase(ListBase&& other) noexcept
    : head_{other.head_},
      tail_{other.tail_},
      allocator_{other.allocator_} {
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.allocator_ = nullptr;
}

template <typename Type>
ListBase<Type>& ListBase<Type>::operator=(ListBase&& other) requires CopyConstructible<Type> {
  /// TODO: implement me!
}

template <typename Type>
ListBase<Type>::~ListBase() noexcept {
  ListNode<Type>* curr_node = head_;
  while (curr_node != nullptr) {
    ListNode<Type>* next_node = curr_node->Next();
    DestroyAt(curr_node);
    allocator_->Deallocate(curr_node, sizeof(ListNode<Type>), MaxAlignment);
    curr_node = next_node;
  }
}

template <typename Type>
void ListBase<Type>::Swap(ListBase& other) noexcept {
  ::std::swap(head_, other.head_);
  ::std::swap(tail_, other.tail_);
  ::std::swap(allocator_, other.allocator_);
}

}  // namespace detail

}  // namespace crutch