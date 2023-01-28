#include "char_traits.hpp"

namespace crutch {

int CharTraits<char>::Compare(const char* lhs, const char* rhs) noexcept {
  ASSERT(lhs != nullptr, "lhs must be a valid pointer");
  ASSERT(rhs != nullptr, "rhs must be a valid pointer");

  return ::std::strcmp(lhs, rhs);
}

int CharTraits<char>::Compare(const char lhs, const char rhs) noexcept {
  return lhs < rhs;
}

void CharTraits<char>::Copy(char* dst, const char* src) noexcept {
  ASSERT(dst != nullptr, "dst must be a valid pointer");
  ASSERT(src != nullptr, "src must be a valid pointer");

  ::std::strcpy(dst, src);
}

SizeType CharTraits<char>::Size(const char* string) noexcept {
  ASSERT(string != nullptr, "string must be a valid pointer");

  return ::std::strlen(string);
}

char CharTraits<char>::ToChar(const int value) noexcept {
  return char(value);
}

int CharTraits<char>::ToInt(const char character) noexcept {
  return int(character);
}

}  // namespace crutch