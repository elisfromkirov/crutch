#ifndef FUNCTOR_IMPL
#error Do not include this file directly
#endif

namespace wheel {

namespace detail {

template <typename Routine, typename ReturnValue, typename... Arguments>
Functor<Routine, ReturnValue(Arguments...)>::Functor(const Routine& routine) requires Copyable<Routine>
    : Routine{routine} {
}

template <typename Routine, typename ReturnValue, typename... Arguments>
Functor<Routine, ReturnValue(Arguments...)>::Functor(Routine&& routine) noexcept requires Moveable<Routine>
    : Routine{::std::move(routine)} {
}

template <typename Routine, typename ReturnValue, typename... Arguments>
ReturnValue Functor<Routine, ReturnValue(Arguments...)>::Invoke(Arguments... arguments) {
  return (*this)(arguments...);
}

}  // namespace detail

}  // namespace wheel