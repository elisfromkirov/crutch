#ifndef LIST_ITERATOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type, typename Allocator>
ListIterator<Type, Allocator>::ListIterator(ListNodePointer node) noexcept
    : node_{node} {
}

template <typename Type, typename Allocator>
bool ListIterator<Type, Allocator>::operator==(const ListIterator& other) const noexcept {
  return node_ == other.node_;
}

template <typename Type, typename Allocator>
bool ListIterator<Type, Allocator>::operator!=(const ListIterator& other) const noexcept {
  return node_ != other.node_;
}

template <typename Type, typename Allocator>
ListIterator<Type, Allocator>& ListIterator<Type, Allocator>::operator++() noexcept {
  node_ = node_->Next();
  return *this;
}

template <typename Type, typename Allocator>
const ListIterator<Type, Allocator> ListIterator<Type, Allocator>::operator++(int) noexcept {
  ListIterator<Type, Allocator> iterator{*this};
  ++(*this);
  return iterator;
}

template <typename Type, typename Allocator>
ListIterator<Type, Allocator>& ListIterator<Type, Allocator>::operator--() noexcept {
  node_ = node_->Prev();
  return *this;
}

template <typename Type, typename Allocator>
const ListIterator<Type, Allocator> ListIterator<Type, Allocator>::operator--(int) noexcept {
  ListIterator<Type, Allocator> iterator{*this};
  --(*this);
  return iterator;
}

template <typename Type, typename Allocator>
Type& ListIterator<Type, Allocator>::operator*() const noexcept {
  return node_->Value();
}

template <typename Type, typename Allocator>
Type* ListIterator<Type, Allocator>::operator->() const noexcept {
  return &node_->Value();
}

}  // namespace detail

}  // namespace crutch