#pragma once

#include <crutch/core/macro/assert.hpp>
#include <crutch/core/type/size.hpp>

namespace crutch {

class SourceLocation {
 public:
  SourceLocation(const char* file, SizeType line, const char* function);

  [[nodiscard]]
  const char* File() const noexcept;

  [[nodiscard]]
  SizeType Line() const noexcept;

  [[nodiscard]]
  const char* Function() const noexcept;

 private:
  const char* file_;
  SizeType line_;
  const char* function_;
};

}  // namespace crutch

