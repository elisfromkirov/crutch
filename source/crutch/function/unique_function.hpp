#pragma once

#include <crutch/concept/copyable.hpp>
#include <crutch/concept/moveable.hpp>

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

#include <crutch/function/detail/unique_function_base.hpp>

namespace crutch {

template <typename ReturnValue, typename... Arguments>
class UniqueFunction;

template <typename ReturnValue, typename... Arguments>
class UniqueFunction<ReturnValue (Arguments...)> {
 public:
  template <typename Closure>
  requires Copyable<Closure> || Moveable<Closure>
  explicit UniqueFunction(Closure&& closure, IAllocator* allocator = GetDefaultAllocator());
  
  ReturnValue operator()(Arguments&&... arguments);
};

}  // namespace crutch

#define UNIQUE_FUNCTION_IMPL
#include <crutch/function/unique_function.ipp>
#undef UNIQUE_FUNCTION_IMPL