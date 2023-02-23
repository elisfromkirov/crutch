#pragma once

#include <wheels/concept/moveable.hpp>
#include <wheels/concept/copyable.hpp>

#include <wheels/core/core.hpp>

#include <wheels/memory/address.hpp>
#include <wheels/memory/placement.hpp>

namespace wheels {

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

}  // namespace wheels

#define OPTIONAL_IMPL
#include <wheels/optional/optional.ipp>
#undef OPTIONAL_IMPL