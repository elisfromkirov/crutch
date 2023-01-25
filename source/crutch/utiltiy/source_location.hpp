#pragma once

#include <crutch/core/assert.hpp>
#include <crutch/core/types.hpp>

#include <crutch/string/view.hpp>

namespace crutch {

class SourceLocation {
 public:
  SourceLocation(const char* file, SizeType line, const char* function);

  [[nodiscard]]
  StringView File() const noexcept;

  [[nodiscard]]
  SizeType Line() const noexcept;

  [[nodiscard]]
  StringView Function() const noexcept;

 private:
  StringView file_;
  SizeType line_;
  StringView function_;
};

}  // namespace crutch

