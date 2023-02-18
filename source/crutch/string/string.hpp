#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/default.hpp>

#include <crutch/string/string_view.hpp>

#include <crutch/string/detail/string_base.hpp>

namespace crutch {

class StringBuilder;

}  // namespace crutch

namespace crutch {

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

}  // namespace crutch