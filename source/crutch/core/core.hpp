#pragma once

#include <cassert>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <exception>
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

using Byte = ::std::uint8_t;

using SizeType = ::std::size_t;

}  // namespace crutch

namespace crutch {

constexpr static SizeType Max(SizeType lhs, SizeType rhs) {
  return lhs < rhs ? rhs : lhs;
}

}  // namespace crutch