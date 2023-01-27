#pragma once

#include <memory>

#include <crutch/container/detail/list.hpp>

namespace crutch {

namespace detail {

template <typename Type>
class ListIterator {
 public:


 private:
  ListNode<Type>* node_;
};

}  // namespace crutch


// const iterator returns const reference
// const iterator returns const pointer

}  // namespace crutch

#define LIST_ITERATOR_IMPL
#include <crutch/container/detail/list_iterator.ipp>
#undef LIST_ITERATOR_IMPL