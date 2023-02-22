#pragma once

#include <wheel/concept/copyable.hpp>
#include <wheel/concept/moveable.hpp>

#include <wheel/core/core.hpp>

#include <wheel/function/detail/invokable.hpp>
#include <wheel/function/detail/functor.hpp>

#include <wheel/memory/allocate.hpp>
#include <wheel/memory/allocator.hpp>
#include <wheel/memory/placement.hpp>
#include <wheel/memory/raw_ptr.hpp>

namespace wheel {

namespace detail {

template <typename ReturnValue, typename... Arguments>
class UniqueFunctionBase;

template <typename ReturnValue, typename... Arguments>
class UniqueFunctionBase<ReturnValue(Arguments...)> {
 public:
  template <typename Routine>
  requires Copyable<Routine> || Moveable<Routine>
  UniqueFunctionBase(Routine&& routine, IAllocator* allocator);

  UniqueFunctionBase(const UniqueFunctionBase& other) = delete;
  UniqueFunctionBase& operator=(const UniqueFunctionBase& other) = delete;

  UniqueFunctionBase(UniqueFunctionBase&& other) noexcept;
  UniqueFunctionBase& operator=(UniqueFunctionBase&& other) noexcept;

 protected:
  ~UniqueFunctionBase() noexcept;

  void Swap(UniqueFunctionBase& other) noexcept;

 protected:
  IInvokable<ReturnValue(Arguments...)>* invokable_;
  IAllocator* allocator_;
};

}  // namespace detail

}  // namespace wheel

#define UNIQUE_FUNCTION_BASE_IMPL
#include <wheel/function/detail/unique_function_base.ipp>
#undef UNIQUE_FUNCTION_BASE_IMPL