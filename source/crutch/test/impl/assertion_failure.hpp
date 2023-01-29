#pragma once

#include <crutch/container/string/view.hpp>

#include <crutch/core/utility/source_location.hpp>

namespace crutch {

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

}  // namespace crutch