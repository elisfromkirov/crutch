#ifndef LIST_IMPL
#error Do not include this file directly
#endif

namespace wheels {

template <typename Type>
IntrusiveNode<Type>* IntrusiveList<Type>::Begin() noexcept {
  return node_.Next();
}

template <typename Type>
IntrusiveNode<Type>* IntrusiveList<Type>::End() noexcept {
  return &node_;
}

template <typename Type>
IntrusiveNode<Type>* IntrusiveList<Type>::Front() noexcept {
  ASSERT(!IsEmpty(), "list must not be empty");

  return node_.Next();
}

template <typename Type>
IntrusiveNode<Type>* IntrusiveList<Type>::Back() noexcept {
  ASSERT(!IsEmpty(), "list must not be empty");

  return node_.Prev();
}

template <typename Type>
bool IntrusiveList<Type>::IsEmpty() const noexcept {
  return !node_.IsLinked();
}

template <typename Type>
void IntrusiveList<Type>::PushFront(IntrusiveNode<Type>* node) noexcept {
  node_.LinkAfter(node);
}

template <typename Type>
void IntrusiveList<Type>::PushBack(IntrusiveNode<Type>* node) noexcept {
  node_.LinkBefore(node);
}

template <typename Type>
void IntrusiveList<Type>::PopFront() noexcept {
  ASSERT(!IsEmpty(), "list must not be empty");

  node_.Next()->Unlink();
}

template <typename Type>
void IntrusiveList<Type>::PopBack() noexcept {
  ASSERT(!IsEmpty(), "list must not be empty");

  node_.Prev()->Unlink();
}

}  // namespace wheels