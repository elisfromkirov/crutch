#pragma once

#include <wheel/core/core.hpp>

#include <wheel/memory/allocator.hpp>
#include <wheel/memory/default.hpp>

#include <wheel/string/string_view.hpp>

#include <wheel/string/detail/string_base.hpp>

namespace wheel {

class StringBuilder;

}  // namespace wheel

namespace wheel {

class String final : private detail::StringBase {
 friend class StringBuilder;

public:
  [[nodiscard]]
  char& operator[](SizeType index) noexcept;

  [[nodiscard]]
  const char& operator[](SizeType index) const noexcept;

  [[nodiscard]]
  char& At(SizeType index) noexcept;

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
  String(char* data, SizeType size, SizeType capacity, IAllocator* allocator) noexcept;

 private:
  [[nodiscard]]
  bool IsValid() const noexcept;
};

}  // namespace wheel