#pragma once

#include <wheel/format/format_traits.hpp>

struct Arg {
};

namespace wheel {

template <>
struct FormatTraits<Arg> {
  static void Format(StringBuilder& builder, [[maybe_unused]] const Arg& value);
};

}  // namespace wheel