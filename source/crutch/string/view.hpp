#pragma once

#include <crutch/core/assert.hpp>
#include <crutch/core/type.hpp>

#include <crutch/type_traits/char_traits.hpp>

namespace crutch {

template <typename CharType, typename CharTraits = CharTraits<CharType>>
class BasicStringView {
 public:
  explicit BasicStringView(const CharType* data) noexcept;

  BasicStringView(const CharType* data, SizeType size) noexcept;

  [[nodiscard]]
  const CharType& operator[](SizeType index) const noexcept;

  [[nodiscard]]
  const CharType& At(SizeType index) const noexcept;

  [[nodiscard]]
  const CharType* Data() const noexcept;

  [[nodiscard]]
  SizeType Size() const noexcept;

 private:
  const CharType* data_;
  SizeType size_;
};

using StringView = BasicStringView<char>;

} // namespace crutch

#define VIEW_IMPL
#include <crutch/string/view.ipp>
#undef VIEW_IMPL