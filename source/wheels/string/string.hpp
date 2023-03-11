#pragma once

#include <wheels/core/core.hpp>

#include <wheels/memory/allocator.hpp>
#include <wheels/memory/default.hpp>

#include <wheels/string/string_view.hpp>

#include <wheels/string/detail/string_base.hpp>

namespace wheels {

class String final : private detail::StringBase {
 friend class StringBuilder;

private:
 String(char* data, SizeType size, SizeType capacity, IAllocator* allocator) noexcept;

public:
  [[nodiscard]]
  const char& operator[](SizeType index) const noexcept;

  [[nodiscard]]
  const char& At(SizeType index) const noexcept;

  [[nodiscard]]
  char* Data() noexcept;

  [[nodiscard]]
  const char* Data() const noexcept;

  [[nodiscard]]
  SizeType Size() const noexcept;

  [[nodiscard]]
  SizeType Capacity() const noexcept;

  [[nodiscard]]
  StringView View() const noexcept;

 private:
  [[nodiscard]]
  bool IsValid() const noexcept;
};

bool operator<(const String& lhs, const String& rhs) noexcept;

bool operator<(const StringView& lhs, const String& rhs) noexcept;

bool operator<(const String& lhs, const StringView& rhs) noexcept;

bool operator<(const StringView& lhs, const StringView& rhs) noexcept;

bool operator==(const String& lhs, const String& rhs) noexcept;

bool operator==(const StringView& lhs, const String& rhs) noexcept;

bool operator==(const String& lhs, const StringView& rhs) noexcept;

bool operator==(const StringView& lhs, const StringView& rhs) noexcept;

bool operator!=(const String& lhs, const String& rhs) noexcept;

bool operator!=(const StringView& lhs, const String& rhs) noexcept;

bool operator!=(const String& lhs, const StringView& rhs) noexcept;

bool operator!=(const StringView& lhs, const StringView& rhs) noexcept;

bool operator>(const String& lhs, const String& rhs) noexcept;

bool operator>(const StringView& lhs, const String& rhs) noexcept;

bool operator>(const String& lhs, const StringView& rhs) noexcept;

bool operator>(const StringView& lhs, const StringView& rhs) noexcept;

}  // namespace wheels