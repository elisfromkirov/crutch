#pragma once

#include <crutch/core/core.hpp>

#include <crutch/string/string_view.hpp>

namespace crutch {

class Error {
 public:
  Error(SizeType value, const char* message) noexcept;

  [[nodiscard]]
  SizeType Value() const noexcept;

  [[nodiscard]]
  StringView Message() const noexcept;

 private:
  SizeType value_;
  StringView message_;
};

}  // namespace crutch