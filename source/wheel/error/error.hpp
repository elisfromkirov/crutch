#pragma once

#include <wheel/core/core.hpp>

#include <wheel/string/string_view.hpp>

namespace wheel {

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

}  // namespace wheel