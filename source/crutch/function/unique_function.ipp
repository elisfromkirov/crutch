#ifndef UNIQUE_FUNCTION_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename ReturnValue, typename... Arguments>
template <typename Closure>
requires Copyable<Closure> || Moveable<Closure>
UniqueFunction<ReturnValue(Arguments...)>::UniqueFunction(Closure&& closure, IAllocator* allocator)
    : detail::UniqueFunctionBase<ReturnValue(Arguments...)>(::std::forward<Closure>(closure), allocator) {
}

template <typename ReturnValue, typename... Arguments>
ReturnValue UniqueFunction<ReturnValue(Arguments...)>::operator()(Arguments&&... arguments) {
  return this->invokable_->Invoke(::std::forward<Arguments>(arguments)...);
}

}  // namespace crutch