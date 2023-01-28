#ifndef CHAR_TRAITS_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename CharType>
int CharTraits<CharType>::Compare(const CharType* lhs, const CharType* rhs) noexcept {
  ASSERT(lhs != nullptr, "lhs must be a valid pointer");
  ASSERT(rhs != nullptr, "rhs must be a valid pointer");

  while (ToInt(*lhs) != 0 && ToInt(*rhs) != 0 && ToInt(*lhs) == ToInt*rhs) {
    ++lhs;
    ++rhs;
  }
  return ToInt(*lhs) < ToInt(*rhs);
}

template <typename CharType>
int CharTraits<CharType>::Compare(CharType lhs, CharType rhs) noexcept {
  return ToInt(lhs) < ToInt(rhs);
}

template <typename CharType>
void CharTraits<CharType>::Copy(CharType* dst, const CharType* src) noexcept {
  ASSERT(dst != nullptr, "dst must be a valid pointer");
  ASSERT(src != nullptr, "src must be a valid pointer");


}

template <typename CharType>
SizeType CharTraits<CharType>::Size(const CharType* string) noexcept {
  ASSERT(string != nullptr, "string must be a valid pointer");

  const CharType* begin = string;
  while (ToInt(*string) != 0) {
    ++string;
  }
  return string - begin;
}

template <typename CharType>
CharType CharTraits<CharType>::ToChar(const int value) noexcept {
  return CharType(value);
}

template <typename CharType>
int CharTraits<CharType>::ToInt(const CharType character) noexcept {
  return int(character);
}

}  // namespace crutch