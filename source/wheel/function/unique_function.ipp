#ifndef UNIQUE_FUNCTION_IMPL
#error Do not include this file directly
#endif

namespace wheel {

template <typename ReturnValue, typename... Arguments>
template <typename Routine,
    typename std::enable_if_t<!std::is_same_v<Routine, UniqueFunction<ReturnValue(Arguments...)>>, int>>
requires Copyable<Routine> || Moveable<Routine>
UniqueFunction<ReturnValue(Arguments...)>::UniqueFunction(Routine&& closure, IAllocator* allocator)
    : detail::UniqueFunctionBase<ReturnValue(Arguments...)>(::std::forward<Routine>(closure), allocator) {
}

template <typename ReturnValue, typename... Arguments>
ReturnValue UniqueFunction<ReturnValue(Arguments...)>::operator()(Arguments... arguments) {
  return this->invokable_->Invoke(arguments...);
}

}  // namespace wheel