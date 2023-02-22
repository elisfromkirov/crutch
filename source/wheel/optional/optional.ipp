#ifndef OPTIONAL_IMPL
#error Do not include this file directly
#endif

namespace wheel {

template <typename Type>
template <typename... Arguments>
requires Constructible<Type, Arguments&&...>
Optional<Type> Optional<Type>::WithValue(Arguments&&... arguments) noexcept(
    kIsNothrowConstructible<Type, Arguments&&...>) {
  Optional<Type> optional{};
  optional.template Emplace(::std::forward<Arguments>(arguments)...);
  return optional;
}

template <typename Type>
Optional<Type>::Optional() noexcept
    : dummy_{},
      state_{kNull} {
}

template <typename Type>
Optional<Type>::Optional(const Optional& other) requires Copyable<Type>
    : dummy_{},
      state_{kNull} {
  if (other.state_ == kValue) {
    ConstructAt(AddressOf(value_), other.value_);
  }
}

template <typename Type>
Optional<Type>& Optional<Type>::operator=(const Optional& other) requires Copyable<Type> {
  if (this != &other) {
    Reset();
    ConstructAt(this, other);
  }
  return *this;
}

template <typename Type>
Optional<Type>::Optional(Optional&& other) noexcept requires Moveable<Type>
    : dummy_{},
      state_{kNull} {
  if (other.state_ == kValue) {
    ConstructAt(AddressOf(value_), ::std::move(other.value_));
    DestroyAt(AddressOf(other.value_));
  }
}

template <typename Type>
Optional<Type>& Optional<Type>::operator=(Optional&& other) noexcept requires Moveable<Type> {
  if (this != &other) {
    Reset();

    ConstructAt(this, ::std::move(other));
  }
  return *this;
}

template <typename Type>
Optional<Type>::~Optional() noexcept {
  Reset();
}

template <typename Type>
Type& Optional<Type>::Value() noexcept {
  ASSERT(state_ == kValue, "optional must contain a value");

  return value_;
}

template <typename Type>
const Type& Optional<Type>::Value() const noexcept {
  ASSERT(state_ == kValue, "optional must contain a value");

  return value_;
}

template <typename Type>
bool Optional<Type>::HasValue() const noexcept {
  return state_ == kValue;
}

template <typename Type>
template <typename... Arguments>
requires Constructible<Type, Arguments&&...>
void Optional<Type>::Emplace(Arguments&&... arguments) noexcept(kIsNothrowConstructible<Type, Arguments&&...>) {
  ASSERT(state_ == kNull, "optional must be empty");

  ConstructAt(AddressOf(value_), ::std::forward<Arguments>(arguments)...);
}

template <typename Type>
void Optional<Type>::Reset() noexcept {
  if (state_ == kValue) {
    state_ = kNull;
    DestroyAt(AddressOf(value_));
  }
}

}  // namespace wheel