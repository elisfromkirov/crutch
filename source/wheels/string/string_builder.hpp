#pragma once

#include <wheels/core/core.hpp>

#include <wheels/memory/allocator.hpp>
#include <wheels/memory/default.hpp>

#include <wheels/string/string.hpp>
#include <wheels/string/string_view.hpp>

#include <wheels/string/detail/string_builder_base.hpp>

namespace wheels {

class StringBuilder final : private detail::StringBuilderBase {
 public:
  static constexpr SizeType kDefaultCapacity{1024};

  static constexpr SizeType kDefaultGrowthFactor{2};

 public:
  explicit StringBuilder(SizeType capacity = kDefaultCapacity, IAllocator* allocator = GetDefaultAllocator());

  explicit StringBuilder(String&& string) noexcept;

  [[nodiscard]]
  char Back() noexcept;

  [[nodiscard]]
  char* Data() noexcept;

  [[nodiscard]]
  bool IsEmpty() const noexcept;

  [[nodiscard]]
  SizeType Size() const noexcept;

  [[nodiscard]]
  SizeType Capacity() const noexcept;

  void Reserve(SizeType capacity);

  void PushBack(char character);

  void PushBack(Int8 value);

  void PushBack(Uint8 value);

  void PushBack(Int16 value);

  void PushBack(Uint16 value);

  void PushBack(Int32 value);

  void PushBack(Uint32 value);

  void PushBack(Int64 value);

  void PushBack(Uint64 value);

  void PushBack(StringView string);

  void PopBack() noexcept;

  String ToString() && noexcept;

 private:
  [[nodiscard]]
  bool IsValid() const noexcept;

  void Ensure(SizeType required_space);

  template <typename Type>
  void PushBackImpl(SizeType required_space, const char* format, Type value);
};

}  // namespace wheels