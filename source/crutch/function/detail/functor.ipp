#ifndef FUNCTOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

namespace detail {

template <typename Closure, typename ReturnValue, typename... Arguments>
Functor<Closure, ReturnValue(Arguments...)>::Functor(const Closure& closure) requires Copyable<Closure>
    : Closure{closure} {
}

template <typename Closure, typename ReturnValue, typename... Arguments>
Functor<Closure, ReturnValue(Arguments...)>::Functor(Closure&& closure) noexcept requires Moveable<Closure>
    : Closure{::std::move(closure)} {
}

template <typename Closure, typename ReturnValue, typename... Arguments>
ReturnValue Functor<Closure, ReturnValue(Arguments...)>::Invoke(Arguments&&... arguments) {
  return (*this)(::std::forward<Arguments>(arguments)...);
}

}  // namespace detail

}  // namespace crutch