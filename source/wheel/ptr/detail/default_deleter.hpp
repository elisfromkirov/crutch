#pragma once

#include <wheel/concept/derived_from.hpp>

#include <wheel/memory/allocator.hpp>
#include <wheel/memory/default.hpp>
#include <wheel/memory/placement.hpp>

namespace wheel {

namespace detail {

template <typename Type>
struct DefaultDeleter {
 public:
  void operator()(Type* object) noexcept;
};

}  // namespace detail

}  // namespace wheel

#define DEFAULT_DELETER_IMPL
#include <wheel/ptr/detail/default_deleter.ipp>
#undef DEFAULT_DELETER_IMPL