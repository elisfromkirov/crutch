#pragma once

#include <wheels/concept/copyable.hpp>
#include <wheels/concept/moveable.hpp>

#include <wheels/core/core.hpp>

#include <wheels/function/detail/unique_function_base.hpp>

#include <wheels/memory/allocator.hpp>
#include <wheels/memory/default.hpp>

namespace wheels {

template <typename ReturnValue, typename... Arguments>
class UniqueFunction;

template <typename ReturnValue, typename... Arguments>
class UniqueFunction<ReturnValue(Arguments...)> final : private detail::UniqueFunctionBase<ReturnValue(Arguments...)> {
 public:
  template <typename Routine,
      typename ::std::enable_if_t<
          !::std::is_same_v<Routine, UniqueFunction<ReturnValue(Arguments...)>>, int> = 0>
  requires Copyable<Routine> || Moveable<Routine>
  explicit UniqueFunction(Routine&& closure, IAllocator* allocator = GetDefaultAllocator());

  ReturnValue operator()(Arguments... arguments);
};

}  // namespace wheels

#define UNIQUE_FUNCTION_IMPL
#include <wheels/function/unique_function.ipp>
#undef UNIQUE_FUNCTION_IMPL