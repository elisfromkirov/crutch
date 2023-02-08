#pragma once

#include <crutch/concept/copyable.hpp>
#include <crutch/concept/moveable.hpp>

#include <crutch/core/core.hpp>

#include <crutch/function/detail/invokable.hpp>

namespace crutch {

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

}  // namespace crutch

#define FUNCTOR_IMPL
#include <crutch/function/detail/functor.ipp>
#undef FUNCTOR_IMPL