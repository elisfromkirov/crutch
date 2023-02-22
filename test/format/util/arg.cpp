#include <format/util/arg.hpp>

namespace wheel {

void FormatTraits<Arg>::Format(StringBuilder& builder, [[maybe_unused]] const Arg& arg) {
  builder.PushBack("custom argument");
}

}  // namespace wheel