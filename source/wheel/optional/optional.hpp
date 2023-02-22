#pragma once

#include <wheel/concept/moveable.hpp>
#include <wheel/concept/copyable.hpp>

#include <wheel/core/core.hpp>

#include <wheel/memory/address.hpp>
#include <wheel/memory/placement.hpp>

namespace wheel {

template <typename Type>
class Optional {
 public:
  template <typename... Arguments>
  requires Constructible<Type, Arguments&&...>
  static Optional<Type> WithValue(Arguments&&... arguments) noexcept(kIsNothrowConstructible<Type, Arguments&&...>);

 private:
  enum State {
    kNull,
    kValue
  };

 public:
  Optional() noexcept;

  Optional(const Optional& other) requires Copyable<Type>;
  Optional& operator=(const Optional& other) requires Copyable<Type>;

  Optional(Optional&& other) noexcept requires Moveable<Type>;
  Optional& operator=(Optional&& other) noexcept requires Moveable<Type>;

  ~Optional() noexcept;

  Type& Value() noexcept;

  const Type& Value() const noexcept;

  [[nodiscard]]
  bool HasValue() const noexcept;

  template <typename... Arguments>
  requires Constructible<Type, Arguments&&...>
  void Emplace(Arguments&&... arguments) noexcept(kIsNothrowConstructible<Type, Arguments&&...>);

  void Reset() noexcept;

 private:
  union alignas(alignof(Type)) {
    Byte dummy_;
    Type value_;
  };
  State state_;
};

}  // namespace wheel

#define OPTIONAL_IMPL
#include <wheel/optional/optional.ipp>
#undef OPTIONAL_IMPL