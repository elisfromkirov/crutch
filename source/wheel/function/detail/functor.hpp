#pragma once

#include <wheel/concept/copyable.hpp>
#include <wheel/concept/moveable.hpp>

#include <wheel/core/core.hpp>

#include <wheel/function/detail/invokable.hpp>

namespace wheel {

namespace detail {

template <typename Routine, typename ReturnValue, typename... Arguments>
class Functor;

template <typename Routine, typename ReturnValue, typename... Arguments>
class Functor<Routine, ReturnValue(Arguments...)> final : public Routine,
                                                          public IInvokable<ReturnValue(Arguments...)> {
 public:
  explicit Functor(const Routine& routine) requires Copyable<Routine>;

  explicit Functor(Routine&& routine) noexcept requires Moveable<Routine>;

  ReturnValue Invoke(Arguments... arguments) override;
};

}  // namespace detail

}  // namespace wheel

#define FUNCTOR_IMPL
#include <wheel/function/detail/functor.ipp>
#undef FUNCTOR_IMPL