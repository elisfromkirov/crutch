#pragma once

#include <wheels/concept/copyable.hpp>
#include <wheels/concept/moveable.hpp>

#include <wheels/core/core.hpp>

#include <wheels/function/detail/invokable.hpp>

namespace wheels {

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

}  // namespace wheels

#define FUNCTOR_IMPL
#include <wheels/function/detail/functor.ipp>
#undef FUNCTOR_IMPL