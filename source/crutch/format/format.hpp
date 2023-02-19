#pragma once

#include <crutch/core/core.hpp>

#include <crutch/format/detail/formatter.hpp>

#include <crutch/string/string.hpp>
#include <crutch/string/string_builder.hpp>

namespace crutch {

template <typename... Types>
String Format(StringBuilder& builder, const char* format, const Types&... values);

template <typename... Types>
String Format(const char* format, const Types&... values);

}  // namespace crutch

#define FORMAT_IMPL
#include <crutch/format/format.ipp>
#undef FORMAT_IMPL