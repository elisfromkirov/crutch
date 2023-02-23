#include <wheels/format/detail/formatter.hpp>

namespace wheels {

namespace detail {

String Formatter<>::Format(StringBuilder& builder, const char* format) {
  while (*format != '\0') {
    builder.PushBack(*format);
    ++format;
  }
  return ::std::move(builder).ToString();
}

}  // namespace detail

}  // namespace wheels