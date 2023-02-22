#pragma once

#include <wheel/concept/copyable.hpp>
#include <wheel/concept/moveable.hpp>

#include <wheel/core/core.hpp>

#include <wheel/function/detail/unique_function_base.hpp>

#include <wheel/memory/allocator.hpp>
#include <wheel/memory/default.hpp>

namespace wheel {

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

}  // namespace wheel

#define UNIQUE_FUNCTION_IMPL
#include <wheel/function/unique_function.ipp>
#undef UNIQUE_FUNCTION_IMPL