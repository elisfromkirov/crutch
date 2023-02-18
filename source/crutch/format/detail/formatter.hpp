#pragma once

#include <crutch/core/core.hpp>

#include <crutch/format/format_traits.hpp>

#include <crutch/string/string.hpp>
#include <crutch/string/string_builder.hpp>

namespace crutch {

namespace detail {

template <typename... Types>
struct Formatter;

template <typename Type, typename... Types>
struct Formatter<Type, Types...> {
  static String Format(StringBuilder& builder, const char* format, const Type& value, const Types&... values);
};

template <>
struct Formatter<> {
  static String Format(StringBuilder& builder, const char* format);
};

}  // namespace detail

}  // namespace crutch

#define FORMATTER_IMPL
#include <crutch/format/detail/formatter.ipp>
#undef FORMATTER_IMPL