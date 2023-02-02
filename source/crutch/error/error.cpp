#include <crutch/error/error.hpp>

namespace crutch {

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

}  // namespace crutch