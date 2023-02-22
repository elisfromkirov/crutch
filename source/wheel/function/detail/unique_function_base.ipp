#ifndef UNIQUE_FUNCTION_BASE_IMPL
#error Do not include this file directly
#endif

namespace wheel {

namespace detail {

template <typename ReturnValue, typename... Arguments>
template <typename Routine>
requires Copyable<Routine> || Moveable<Routine>
UniqueFunctionBase<ReturnValue(Arguments...)>::UniqueFunctionBase(Routine&& routine, IAllocator* allocator)
    : invokable_{nullptr},
      allocator_{allocator} {
  auto ptr = Allocate<Functor<Routine, ReturnValue(Arguments...)>>(allocator);
  invokable_ = Construct(::std::move(ptr), ::std::forward<Routine>(routine));
}

template <typename ReturnValue, typename... Arguments>
UniqueFunctionBase<ReturnValue(Arguments...)>::UniqueFunctionBase(UniqueFunctionBase&& other) noexcept
    : invokable_{other.invokable_},
      allocator_{other.allocator_} {
  other.invokable_ = nullptr;
}

template <typename ReturnValue, typename... Arguments>
UniqueFunctionBase<ReturnValue(Arguments...)>& UniqueFunctionBase<ReturnValue(Arguments...)>::operator=(
    UniqueFunctionBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  UniqueFunctionBase<ReturnValue(Arguments...)> tmp{::std::move(other)};
  Swap(tmp);

  return *this;
}

template <typename ReturnValue, typename... Arguments>
UniqueFunctionBase<ReturnValue(Arguments...)>::~UniqueFunctionBase() noexcept {
  auto ptr = Destroy(invokable_, allocator_);
}

template <typename ReturnValue, typename... Arguments>
void UniqueFunctionBase<ReturnValue(Arguments...)>::Swap(UniqueFunctionBase& other) noexcept {
  ::std::swap(invokable_, other.invokable_);
  ::std::swap(allocator_, other.allocator_);
}

}  // namespace detail

}  // namespace wheel