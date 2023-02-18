#include <format/util/arg.hpp>

namespace crutch {

void FormatTraits<Arg>::Format(StringBuilder& builder, [[maybe_unused]] const Arg& arg) {
  builder.PushBack("custom argument");
}

}  // namespace crutch