#include <format/util/arg.hpp>

namespace wheels {

void FormatTraits<Arg>::Format(StringBuilder& builder, [[maybe_unused]] const Arg& arg) {
  builder.PushBack("custom argument");
}

}  // namespace wheels