#ifndef LIST_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type>
IntrusiveNode<Type>* IntrusiveList<Type>::Head() noexcept {
  return node_.Next();
}

template <typename Type>
IntrusiveNode<Type>* IntrusiveList<Type>::Tail() noexcept {
  return &node_;
}

template <typename Type>
bool IntrusiveList<Type>::IsEmpty() const noexcept {
  return !node_.IsLinked();
}

template <typename Type>
void IntrusiveList<Type>::Insert(IntrusiveNode<Type>* node) noexcept {
  node_.LinkBefore(node);
}

}  // namespace crutch