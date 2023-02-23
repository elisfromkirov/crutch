#pragma once

#include <wheels/macro/abort.hpp>

#include <wheels/string/string_builder.hpp>

namespace wheels {

template <typename Type>
struct FormatTraits {
  static void Format(StringBuilder& builder, const Type& value);
};

}  // namespace wheels

#define FORMAT_TRAITS_IMPL
#include <wheels/format/format_traits.ipp>
#undef FORMAT_TRAITS_IMPL