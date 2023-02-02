#pragma once

#include <crutch/concept/copyable.hpp>
#include <crutch/concept/moveable.hpp>

#include <crutch/core/core.hpp>

#include <crutch/function/detail/invokable.hpp>

namespace crutch {

namespace detail {

template <typename Closure, typename ReturnValue, typename... Arguments>
class Functor;

template <typename Closure, typename ReturnValue, typename... Arguments>
class Functor<Closure, ReturnValue(Arguments...)> final : public Closure,
                                                          public IInvokable<ReturnValue(Arguments...)> {
 public:
  explicit Functor(const Closure& closure) requires Copyable<Closure>;

  explicit Functor(Closure&& closure) noexcept requires Moveable<Closure>;

  ReturnValue Invoke(Arguments&&... arguments) override;
};

}  // namespace detail

}  // namespace crutch

#define FUNCTOR_IMPL
#include <crutch/function/detail/functor.ipp>
#undef FUNCTOR_IMPL