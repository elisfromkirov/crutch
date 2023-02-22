#include <wheel/error/error.hpp>

namespace wheel {

Error::Error(SizeType value, const char* message) noexcept
    : value_{value},
      message_{message} {
}

SizeType Error::Value() const noexcept {
  return value_;
}

StringView Error::Message() const noexcept {
  return message_;
}

}  // namespace wheel