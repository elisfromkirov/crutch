#pragma once

#include <crutch/core/macro/assert.hpp>
#include <crutch/core/type/size.hpp>

#include <cstring>

namespace crutch {

/**
 * @brief Basic operations on character sequences.
 */
template <typename CharType>
struct CharTraits {
  /**
   * @brief Compares given zero-terminated character sequences.
   *
   * @param lhs Pointer to first character sequence to compare.
   * @param rhs Pointer to second character sequence to compare.
   *
   * @return Positive integer whether first sequence grater than second,
   *         negative integer whether second sequence grater than first
   *         or zero whether sequences are equal.
   */
  static int Compare(const CharType* lhs, const CharType* rhs) noexcept;

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
  static int Compare(CharType lhs, CharType rhs) noexcept;

  /**
   * @brief Copies character sequence.
   *
   * @param dst Character sequence to which will be copied.
   * @param src Character sequence to copy.
   */
  static void Copy(CharType* dst, const CharType* src) noexcept;

  /**
   * @brief Calculates length of given zero terminated character sequence.
   *
   * @param string Pointer to character sequence.
   */
  static SizeType Size(const CharType* string) noexcept;

  /**
   * @brief Converts given integer value to character.
   *
   * @param value Value to be converted.
   */
   static CharType ToChar(int value) noexcept;

   /**
   * @brief Converts given character to integer value.
   *
   * @param character Character to be converted.
    */
   static int ToInt(CharType character) noexcept;
};

/**
 * @brief Basic operations on character sequences.
 */
template <>
struct CharTraits<char> {
  /**
   * @brief Compares given zero terminated character sequences.
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
   * @brief Calculates length of given zero terminated character sequence.
   *
   * @param string Pointer to character sequence.
   */
  static SizeType Size(const char* string) noexcept;

  /**
   * @brief Converts given integer value to character.
   *
   * @param value Value to be converted.
   */
  static char ToChar(int value) noexcept;

  /**
   * @brief Converts given character to integer value.
   *
   * @param character Character to be converted.
   */
  static int ToInt(char character) noexcept;
};

}  // namespace crutch

#define CHAR_TRAITS_IMPL
#include <crutch/core/type_traits/char_traits.ipp>
#undef CHAR_TRAITS_IMPL