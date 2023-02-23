#pragma once

#include <wheels/string/string_view.hpp>

#include <wheels/utility/source_location.hpp>

namespace wheels {

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

}  // namespace wheels