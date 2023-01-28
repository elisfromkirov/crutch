#ifndef LIST_CONST_ITERATOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Type, typename Allocator>
ListConstIterator<Type, Allocator>::ListConstIterator(ListNodeConstPointer node) noexcept
    : node_{node} {
}

template <typename Type, typename Allocator>
bool ListConstIterator<Type, Allocator>::operator==(const ListConstIterator& other) const noexcept {
  return node_ == other.node_;
}

template <typename Type, typename Allocator>
bool ListConstIterator<Type, Allocator>::operator!=(const ListConstIterator& other) const noexcept {
  return node_ != other.node_;
}

template <typename Type, typename Allocator>
ListConstIterator<Type, Allocator>& ListConstIterator<Type, Allocator>::operator++() noexcept {
  node_ = node_->Next();
  return *this;
}

template <typename Type, typename Allocator>
const ListConstIterator<Type, Allocator> ListConstIterator<Type, Allocator>::operator++(
    int) noexcept {
  ListConstIterator<Type, Allocator> iterator{*this};
  ++(*this);
  return iterator;
}

template <typename Type, typename Allocator>
ListConstIterator<Type, Allocator>& ListConstIterator<Type, Allocator>::operator--() noexcept {
  node_ = node_->Prev();
  return *this;
}

template <typename Type, typename Allocator>
const ListConstIterator<Type, Allocator> ListConstIterator<Type, Allocator>::operator--(
    int) noexcept {
  ListConstIterator<Type, Allocator> iterator{*this};
  --(*this);
  return iterator;
}

template <typename Type, typename Allocator>
const Type& ListConstIterator<Type, Allocator>::operator*() const noexcept {
  return node_->Value();
}

template <typename Type, typename Allocator>
const Type* ListConstIterator<Type, Allocator>::operator->() const noexcept {
  return &node_->Value();
}

}  // namespace detail

}  // namespace crutch