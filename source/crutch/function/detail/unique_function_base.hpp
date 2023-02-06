#pragma once

#include <crutch/concept/copyable.hpp>
#include <crutch/concept/moveable.hpp>

#include <crutch/core/core.hpp>

#include <crutch/function/detail/invokable.hpp>
#include <crutch/function/detail/functor.hpp>

#include <crutch/memory/allocate.hpp>
#include <crutch/memory/allocator.hpp>
#include <crutch/memory/placement.hpp>
#include <crutch/memory/raw_ptr.hpp>

namespace crutch {

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

}  // namespace crutch

#define UNIQUE_FUNCTION_BASE_IMPL
#include <crutch/function/detail/unique_function_base.ipp>
#undef UNIQUE_FUNCTION_BASE_IMPL