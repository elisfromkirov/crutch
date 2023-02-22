#pragma once

#include <wheel/string/string_view.hpp>

#include <wheel/utility/source_location.hpp>

namespace wheel {

class AssertionFailure {
 public:
  AssertionFailure(const char* expression, SourceLocation location);

  [[nodiscard]]
  StringView Expression() const noexcept;

  [[nodiscard]]
  const SourceLocation& Location() const noexcept;

 private:
  StringView expression_;
  SourceLocation location_;
};

}  // namespace wheel