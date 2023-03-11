#ifndef RESULT_IMPL
#error Do not include this file directly
#endif

namespace wheels {

template <typename Type, typename ErrorType>
template <typename... Arguments>
requires Constructible<Type, Arguments&&...>
Result<Type, ErrorType> Result<Type, ErrorType>::WithValue(Arguments&&... arguments) noexcept(
    kIsNothrowConstructible<Type, Arguments&&...>) {
  Result<Type, ErrorType> result{};
  result.template EmplaceValue(::std::forward<Arguments>(arguments)...);
  return result;
}

template <typename Type, typename ErrorType>
template <typename... Arguments>
requires Constructible<ErrorType, Arguments&&...>
Result<Type, ErrorType> Result<Type, ErrorType>::WithError(Arguments&&... arguments) noexcept(
    kIsNothrowConstructible<ErrorType, Arguments&&...>) {
  Result<Type, ErrorType> result{};
  result.template EmplaceError(::std::forward<Arguments>(arguments)...);
  return result;
}

template <typename Type, typename ErrorType>
Result<Type, ErrorType>::Result() noexcept
    : dummy_{},
      state_{kNull} {
}

template <typename Type, typename ErrorType>
Result<Type, ErrorType>::Result(const Result& other) requires Copyable<Type>
    : dummy_{},
      state_{kNull} {
  switch (other.state_) {
    case kValue:
      ConstructAt(AddressOf(value_), other.value_);
      break;
    case kError:
      ConstructAt(AddressOf(error_), other.error_);
      break;
    default:
      UNREACHABLE();
  }
}

template <typename Type, typename ErrorType>
Result<Type, ErrorType>& Result<Type, ErrorType>::operator=(const Result& other) requires Copyable<Type> {
  if (this != &other) {
    Reset();
    ConstructAt(this, other);
  }
  return *this;
}

template <typename Type, typename ErrorType>
Result<Type, ErrorType>::Result(Result&& other) noexcept requires Moveable<Type>
    : dummy_{},
      state_{kNull} {
  switch (other.state_) {
    case kValue:
      ConstructAt(AddressOf(value_), ::std::move(other.value_));
      break;
    case kError:
      ConstructAt(AddressOf(error_), ::std::move(other.error_));
      break;
    default:
      UNREACHABLE();
  }
}

template <typename Type, typename ErrorType>
Result<Type, ErrorType>& Result<Type, ErrorType>::operator=(Result&& other) noexcept requires Moveable<Type> {
  if (this != &other) {
    Reset();
    ConstructAt(this, ::std::move(other));
  }
  return *this;
}

template <typename Type, typename ErrorType>
Result<Type, ErrorType>::~Result() noexcept {
  Reset();
}

template <typename Type, typename ErrorType>
Type& Result<Type, ErrorType>::Value() noexcept {
  ASSERT(state_ == kValue, "result must contain a value");

  return value_;
}

template <typename Type, typename ErrorType>
const Type& Result<Type, ErrorType>::Value() const noexcept {
  ASSERT(state_ == kValue, "result must contain a value");

  return value_;
}

template <typename Type, typename ErrorType>
ErrorType& Result<Type, ErrorType>::Error() noexcept {
  ASSERT(state_ == kError, "result must contain an error");

  return error_;
}

template <typename Type, typename ErrorType>
const ErrorType& Result<Type, ErrorType>::Error() const noexcept {
  ASSERT(state_ == kError, "result must contain an error");

  return error_;
}

template <typename Type, typename ErrorType>
bool Result<Type, ErrorType>::HasValue() const noexcept {
  return state_ == kValue;
}

template <typename Type, typename ErrorType>
bool Result<Type, ErrorType>::HasError() const noexcept {
  return state_ == kError;
}

template <typename Type, typename ErrorType>
template <typename... Arguments>
requires Constructible<Type, Arguments&&...>
void Result<Type, ErrorType>::EmplaceValue(Arguments&&... arguments) noexcept(
    kIsNothrowConstructible<Type, Arguments&&...>) {
  ASSERT(state_ == kNull, "result must be empty");

  ConstructAt(AddressOf(value_), ::std::forward<Arguments>(arguments)...);
}

template <typename Type, typename ErrorType>
template <typename... Arguments>
requires Constructible<ErrorType, Arguments&&...>
void Result<Type, ErrorType>::EmplaceError(Arguments&&... arguments) noexcept(
    kIsNothrowConstructible<ErrorType, Arguments&&...>) {
  ASSERT(state_ == kNull, "result must be empty");

  ConstructAt(AddressOf(error_), ::std::forward<Arguments>(arguments)...);
}

template <typename Type, typename ErrorType>
void Result<Type, ErrorType>::Reset() noexcept {
  switch (state_) {
    case kValue:
      DestroyAt(AddressOf(value_));
      break;
    case kError:
      DestroyAt(AddressOf(error_));
      break;
    default:
      UNREACHABLE();
  }
  state_ = kNull;
}

}  // namespace wheels