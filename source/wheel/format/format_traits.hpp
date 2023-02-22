#pragma once

#include <wheel/macro/abort.hpp>

#include <wheel/string/string_builder.hpp>

namespace wheel {

template <typename Type>
struct FormatTraits {
  static void Format(StringBuilder& builder, const Type& value);
};

}  // namespace wheel

#define FORMAT_TRAITS_IMPL
#include <wheel/format/format_traits.ipp>
#undef FORMAT_TRAITS_IMPL