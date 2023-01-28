#pragma once

#include <crutch/core/assert.hpp>
#include <crutch/core/type.hpp>

#include <cstring>

namespace crutch {

template <typename CharType>
struct CharTraits;

/**
 * @brief Basic operations on character sequences.
 */
template <>
struct CharTraits<char> {
  /**
   * @brief Compares given character sequences.
   *
   * @param lhs Pointer to first character sequence to compare.
   * @param rhs Pointer to second character sequence to compare.
   *
   * @return Positive integer whether first sequence grater than second,
   *         negative integer whether second sequence grater than first
   *         or zero whether sequences are equal.
   */
  static int Compare(const char* lhs, const char* rhs) noexcept;

  /**
   * @brief Compares given characters.
   *
   * @param lhs First character to compare.
   * @param rhs Second character to compare.
   *
   * @return Positive integer whether first sequence grater than second,
   *         negative integer whether second sequence grater than first
   *         or zero whether sequences are equal.
   */
  static int Compare(char lhs, char rhs) noexcept;

  /**
   * @brief Copies character sequence.
   *
   * @param dst Character sequence to which will be copied.
   * @param src Character sequence to copy.
   */
  static void Copy(char* dst, const char* src) noexcept;

  /**
   * @brief Calculates length of given character sequence.
   *
   * @param string Pointer to character sequence.
   */
  static SizeType Size(const char* string) noexcept;
};

}  // namespace crutch

#define CHAR_TRAITS_IMPL
#include <crutch/type_traits/char_traits.ipp>
#undef CHAR_TRAITS_IMPL