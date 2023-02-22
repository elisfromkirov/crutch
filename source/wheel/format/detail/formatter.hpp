#pragma once

#include <wheel/core/core.hpp>

#include <wheel/format/format_traits.hpp>

#include <wheel/string/string.hpp>
#include <wheel/string/string_builder.hpp>

namespace wheel {

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

}  // namespace wheel

#define FORMATTER_IMPL
#include <wheel/format/detail/formatter.ipp>
#undef FORMATTER_IMPL