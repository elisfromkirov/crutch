#pragma once

#include <wheels/concept/copyable.hpp>
#include <wheels/concept/moveable.hpp>

#include <wheels/core/core.hpp>

#include <wheels/function/detail/invokable.hpp>
#include <wheels/function/detail/functor.hpp>

#include <wheels/memory/allocate.hpp>
#include <wheels/memory/allocator.hpp>
#include <wheels/memory/placement.hpp>
#include <wheels/memory/raw_ptr.hpp>

namespace wheels {

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

}  // namespace wheels

#define UNIQUE_FUNCTION_BASE_IMPL
#include <wheels/function/detail/unique_function_base.ipp>
#undef UNIQUE_FUNCTION_BASE_IMPL