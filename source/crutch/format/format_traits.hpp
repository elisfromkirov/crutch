#pragma once

#include <crutch/macro/abort.hpp>

#include <crutch/string/string_builder.hpp>

namespace crutch {

template <typename Type>
struct FormatTraits {
  static void Format(StringBuilder& builder, const Type& value);
};

}  // namespace crutch

#define FORMAT_TRAITS_IMPL
#include <crutch/format/format_traits.ipp>
#undef FORMAT_TRAITS_IMPL