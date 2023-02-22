#pragma once

#include <wheel/concept/moveable.hpp>
#include <wheel/concept/copyable.hpp>

#include <wheel/core/core.hpp>

#include <wheel/error/error.hpp>

#include <wheel/macro/unreachable.hpp>

#include <wheel/memory/address.hpp>
#include <wheel/memory/placement.hpp>

namespace wheel {

template <typename Type, typename ErrorType = Error>
class Result {
 public:
  template <typename... Arguments>
  requires Constructible<Type, Arguments&&...>
  static Result<Type, ErrorType> WithValue(Arguments&&... arguments) noexcept(
      kIsNothrowConstructible<Type, Arguments&&...>);

  template <typename... Arguments>
  requires Constructible<ErrorType, Arguments&&...>
  static Result<Type, ErrorType> WithError(Arguments&&... arguments) noexcept(
      kIsNothrowConstructible<ErrorType, Arguments&&...>);

 private:
  enum State {
    kNull,
    kValue,
    kError
  };

 public:
  Result() noexcept;

  Result(const Result& other) requires Copyable<Type>;
  Result& operator=(const Result& other) requires Copyable<Type>;

  Result(Result&& other) noexcept requires Moveable<Type>;
  Result& operator=(Result&& other) noexcept requires Moveable<Type>;

  ~Result() noexcept;

  Type& Value() noexcept;

  const Type& Value() const noexcept;

  ErrorType& Error() noexcept;

  const ErrorType& Error() const noexcept;

  [[nodiscard]]
  bool HasValue() const noexcept;

  [[nodiscard]]
  bool HasError() const noexcept;

  template <typename... Arguments>
  requires Constructible<Type, Arguments&&...>
  void EmplaceValue(Arguments&&... arguments) noexcept(kIsNothrowConstructible<Type, Arguments&&...>);

  template <typename... Arguments>
  requires Constructible<ErrorType, Arguments&&...>
  void EmplaceError(Arguments&&... arguments) noexcept(kIsNothrowConstructible<ErrorType, Arguments&&...>);

  void Reset() noexcept;

 private:
  union alignas(Max(alignof(Type), alignof(ErrorType))) {
    Byte dummy_;
    Type value_;
    ErrorType error_;
  };
  State state_;
};

}  // namespace wheel

#define RESULT_IMPL
#include <wheel/result/result.ipp>
#undef RESULT_IMPL