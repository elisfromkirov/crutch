#pragma once

#include <wheels/core/core.hpp>

#include <wheels/string/string_view.hpp>

namespace wheels {

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

}  // namespace wheels