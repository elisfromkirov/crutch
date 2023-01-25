#ifndef VIEW_IMPL
#error Do not include this file directly
#endif

#include <string>

namespace crutch {

template <typename CharType, typename CharTraits>
BasicStringView<CharType, CharTraits>::BasicStringView(const CharType* data) noexcept
    : data_{data},
      size_{CharTraits::Size(data)} {
  ASSERT(data != nullptr, "data must be a valid pointer");
}

template <typename CharType, typename CharTraits>
BasicStringView<CharType, CharTraits>::BasicStringView(const CharType* data, SizeType size) noexcept
    : data_{data},
      size_{size} {
  ASSERT(data != nullptr, "data must be a valid pointer");
}

template <typename CharType, typename CharTraits>
const CharType& BasicStringView<CharType, CharTraits>::operator[](SizeType index) const noexcept {
  ASSERT(data_ != nullptr, "internal error");
  ASSERT(index < size_, "index must be less than size");

  return data_[index];
}

template <typename CharType, typename CharTraits>
const CharType& BasicStringView<CharType, CharTraits>::At(SizeType index) const noexcept {
  ASSERT(data_ != nullptr, "internal error");
  ASSERT(index < size_, "index must be less than size");

  return data_[index];
}

template <typename CharType, typename CharTraits>
const CharType* BasicStringView<CharType, CharTraits>::Data() const noexcept {
  ASSERT(data_ != nullptr, "internal error");

  return data_;
}

template <typename CharType, typename CharTraits>
SizeType BasicStringView<CharType, CharTraits>::Size() const noexcept {
  return size_;
}

}  // namespace crutch