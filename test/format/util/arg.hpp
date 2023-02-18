#pragma once

#include <crutch/format/format_traits.hpp>

struct Arg {
};

namespace crutch {

template <>
struct FormatTraits<Arg> {
  static void Format(StringBuilder& builder, [[maybe_unused]] const Arg& value);
};

}  // namespace crutch