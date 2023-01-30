#ifndef LIST_ITERATOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type>
ListIterator<Type>::ListIterator(detail::ListNode<Type>* node) noexcept
    : node_{node} {
}

template <typename Type>
bool ListIterator<Type>::operator==(const ListIterator& other) const noexcept {
  return node_ == other.node_;
}

template <typename Type>
bool ListIterator<Type>::operator!=(const ListIterator& other) const noexcept {
  return node_ != other.node_;
}

template <typename Type>
ListIterator<Type>& ListIterator<Type>::operator++() noexcept {
  ASSERT(node_ != nullptr, "iterator is invalid");

  node_ = node_->Next();
  return *this;
}

template <typename Type>
const ListIterator<Type> ListIterator<Type>::operator++(int) noexcept {
  ListIterator<Type> iterator{*this};
  ++(*this);
  return iterator;
}

template <typename Type>
ListIterator<Type>& ListIterator<Type>::operator--() noexcept {
  ASSERT(node_ != nullptr, "iterator is invalid");

  node_ = node_->Prev();
  return *this;
}

template <typename Type>
const ListIterator<Type> ListIterator<Type>::operator--(int) noexcept {
  ListIterator<Type> iterator{*this};
  --(*this);
  return iterator;
}

template <typename Type>
Type& ListIterator<Type>::operator*() const noexcept {
  ASSERT(node_ != nullptr, "iterator is invalid");

  return node_->Value();
}

template <typename Type>
Type* ListIterator<Type>::operator->() const noexcept {
  ASSERT(node_ != nullptr, "iterator is invalid");

  return AddressOf(node_->Value());
}

}  // namespace crutch