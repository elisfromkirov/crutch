#pragma once

#include <wheels/format/format_traits.hpp>

struct Arg {
};

namespace wheels {

template <>
struct FormatTraits<Arg> {
  static void Format(StringBuilder& builder, const Arg& value);
};

}  // namespace wheels