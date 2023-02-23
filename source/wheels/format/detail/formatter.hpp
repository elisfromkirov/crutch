#pragma once

#include <wheels/core/core.hpp>

#include <wheels/format/format_traits.hpp>

#include <wheels/string/string.hpp>
#include <wheels/string/string_builder.hpp>

namespace wheels {

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

}  // namespace wheels

#define FORMATTER_IMPL
#include <wheels/format/detail/formatter.ipp>
#undef FORMATTER_IMPL