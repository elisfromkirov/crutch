#ifndef LIST_CONST_ITERATOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type>
ListConstIterator<Type>::ListConstIterator(const detail::ListNode<Type>* node) noexcept
    : node_{node} {
}

template <typename Type>
bool ListConstIterator<Type>::operator==(const ListConstIterator& other) const noexcept {
  return node_ == other.node_;
}

template <typename Type>
bool ListConstIterator<Type>::operator!=(const ListConstIterator& other) const noexcept {
  return node_ != other.node_;
}

template <typename Type>
ListConstIterator<Type>& ListConstIterator<Type>::operator++() noexcept {
  ASSERT(node_ != nullptr, "iterator is invalid");

  node_ = node_->Next();
  return *this;
}

template <typename Type>
const ListConstIterator<Type> ListConstIterator<Type>::operator++(int) noexcept {
  ListConstIterator<Type> iterator{*this};
  ++(*this);
  return iterator;
}

template <typename Type>
ListConstIterator<Type>& ListConstIterator<Type>::operator--() noexcept {
  ASSERT(node_ != nullptr, "iterator is invalid");

  node_ = node_->Prev();
  return *this;
}

template <typename Type>
const ListConstIterator<Type> ListConstIterator<Type>::operator--(int) noexcept {
  ListConstIterator<Type> iterator{*this};
  --(*this);
  return iterator;
}

template <typename Type>
const Type& ListConstIterator<Type>::operator*() const noexcept {
  ASSERT(node_ != nullptr, "iterator is invalid");

  return node_->Value();
}

template <typename Type>
const Type* ListConstIterator<Type>::operator->() const noexcept {
  ASSERT(node_ != nullptr, "iterator is invalid");

  return AddressOf(node_->Value());
}

}  // namespace crutch