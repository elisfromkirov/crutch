#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

class StringView {
 public:
  StringView() noexcept;

  StringView(const char* data) noexcept;

  StringView(const char* data, SizeType size) noexcept;

  [[nodiscard]]
  const char& operator[](SizeType index) const noexcept;

  [[nodiscard]]
  const char& At(SizeType index) const noexcept;

  [[nodiscard]]
  const char* Data() const noexcept;

  [[nodiscard]]
  SizeType Size() const noexcept;

 private:
  const char* data_;
  SizeType size_;
};

} // namespace wheels