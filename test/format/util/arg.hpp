#pragma once

#include <wheels/format/format_traits.hpp>

struct Arg {
};

namespace wheels {

template <>
struct FormatTraits<Arg> {
  static void Format(StringBuilder& builder, [[maybe_unused]] const Arg& value);
};

}  // namespace wheels