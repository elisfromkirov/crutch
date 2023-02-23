#pragma once

#include <wheels/concept/derived_from.hpp>

#include <wheels/memory/allocator.hpp>
#include <wheels/memory/default.hpp>
#include <wheels/memory/placement.hpp>

namespace wheels {

namespace detail {

template <typename Type>
struct DefaultDeleter {
 public:
  void operator()(Type* object) noexcept;
};

}  // namespace detail

}  // namespace wheels

#define DEFAULT_DELETER_IMPL
#include <wheels/ptr/detail/default_deleter.ipp>
#undef DEFAULT_DELETER_IMPL