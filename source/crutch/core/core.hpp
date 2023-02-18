#pragma once

#include <cassert>
#include <cinttypes>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <exception>
#include <limits>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

#define ASSERT(expression, message)    \
  do {                                 \
    if (!(expression)) {               \
      assert((expression) || message); \
    }                                  \
  } while (false)

namespace crutch {

using Byte = ::std::uint8_t;

using SizeType = ::std::size_t;

}  // namespace crutch

namespace crutch {

using Int8 = ::std::int8_t;

using Int16 = ::std::int16_t;

using Int32 = ::std::int32_t;

using Int64 = ::std::int64_t;

using Uint8 = ::std::uint8_t;

using Uint16 = ::std::uint16_t;

using Uint32 = ::std::uint32_t;

using Uint64 = ::std::uint64_t;

}  // namespace crutch

namespace crutch {

template <typename Type>
struct Limits;

template <>
struct Limits<Int8> {
  static constexpr Int8 kMin = ::std::numeric_limits<Int8>::max();

  static constexpr Int8 kMax = ::std::numeric_limits<Int8>::max();

  static constexpr SizeType kDigits = 4;
};

template <>
struct Limits<Uint8> {
  static constexpr Uint8 kMin = ::std::numeric_limits<Uint8>::max();

  static constexpr Uint8 kMax = ::std::numeric_limits<Uint8>::max();

  static constexpr SizeType kDigits = 3;
};

template <>
struct Limits<Int16> {
  static constexpr Int16 kMin = ::std::numeric_limits<Int16>::max();

  static constexpr Int16 kMax = ::std::numeric_limits<Int16>::max();

  static constexpr SizeType kDigits = 6;
};

template <>
struct Limits<Uint16> {
  static constexpr Uint16 kMin = ::std::numeric_limits<Uint16>::max();

  static constexpr Uint16 kMax = ::std::numeric_limits<Uint16>::max();

  static constexpr SizeType kDigits = 5;
};

template <>
struct Limits<Int32> {
  static constexpr Int32 kMin = ::std::numeric_limits<Int32>::max();

  static constexpr Int32 kMax = ::std::numeric_limits<Int32>::max();

  static constexpr SizeType kDigits = 11;
};

template <>
struct Limits<Uint32> {
  static constexpr Uint32 kMin = ::std::numeric_limits<Uint32>::max();

  static constexpr Uint32 kMax = ::std::numeric_limits<Uint32>::max();

  static constexpr SizeType kDigits = 10;
};

template <>
struct Limits<Int64> {
  static constexpr Int64 kMin = ::std::numeric_limits<Int64>::max();

  static constexpr Int64 kMax = ::std::numeric_limits<Int64>::max();

  static constexpr SizeType kDigits = 20;
};

template <>
struct Limits<Uint64> {
  static constexpr Uint64 kMin = ::std::numeric_limits<Uint64>::max();

  static constexpr Uint64 kMax = ::std::numeric_limits<Uint64>::max();

  static constexpr SizeType kDigits = 19;
};

}  // namespace crutch

namespace crutch {

constexpr static SizeType Max(SizeType lhs, SizeType rhs) {
  return lhs < rhs ? rhs : lhs;
}

}  // namespace crutch

namespace crutch {

template <typename Type, typename OtherType = Type>
constexpr Type Exchange(Type& value, OtherType&& new_value) {
  return ::std::exchange(value, ::std::forward<OtherType>(new_value));
}

}  // namespace crutch