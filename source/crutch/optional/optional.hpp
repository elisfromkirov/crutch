#pragma once

#include <crutch/concept/moveable.hpp>
#include <crutch/concept/copyable.hpp>

#include <crutch/core/core.hpp>

#include <crutch/memory/address.hpp>
#include <crutch/memory/placement.hpp>

namespace crutch {

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

}  // namespace crutch

#define OPTIONAL_IMPL
#include <crutch/optional/optional.ipp>
#undef OPTIONAL_IMPL