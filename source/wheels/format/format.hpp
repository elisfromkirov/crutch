#pragma once

#include <wheels/core/core.hpp>

#include <wheels/format/detail/formatter.hpp>

#include <wheels/string/string.hpp>
#include <wheels/string/string_builder.hpp>

namespace wheels {

template <typename... Types>
String Format(StringBuilder& builder, const char* format, const Types&... values);

template <typename... Types>
String Format(const char* format, const Types&... values);

}  // namespace wheels

#define FORMAT_IMPL
#include <wheels/format/format.ipp>
#undef FORMAT_IMPL