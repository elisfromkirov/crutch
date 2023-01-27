#pragma once

#include <crutch/allocator/new.hpp>

#include <crutch/concept/allocator_for.hpp>
#include <crutch/concept/is_not_reference.hpp>

#include <crutch/container/detail/list_base.hpp>
#include <crutch/container/detail/list_iterator.hpp>
#include <crutch/container/detail/list_node.hpp>

namespace crutch {

template <typename Type, AllocatorFor<Type> Allocator>
class List {
 public:

};

}  // namespace crutch

#define LIST_IMPL
#include <crutch/container/list.ipp>
#undef LIST_IMPL