#pragma once

#include <wheel/core/core.hpp>

#include <wheel/format/detail/formatter.hpp>

#include <wheel/string/string.hpp>
#include <wheel/string/string_builder.hpp>

namespace wheel {

template <typename... Types>
String Format(StringBuilder& builder, const char* format, const Types&... values);

template <typename... Types>
String Format(const char* format, const Types&... values);

}  // namespace wheel

#define FORMAT_IMPL
#include <wheel/format/format.ipp>
#undef FORMAT_IMPL