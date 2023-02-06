#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/default.hpp>

#include <crutch/string/string.hpp>
#include <crutch/string/string_view.hpp>

#include <crutch/string/detail/string_builder_base.hpp>

namespace crutch {

class StringBuilder final : private detail::StringBuilderBase {
 public:
  static constexpr SizeType default_capacity{1024};

  static constexpr SizeType default_growth_factor{2};

 public:
  explicit StringBuilder(SizeType capacity = default_capacity, IAllocator* allocator = GetDefaultAllocator());

  explicit StringBuilder(const String& string);

  explicit StringBuilder(String&& string) noexcept;

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

}  // namespace crutch