#pragma once

#include <wheel/core/core.hpp>

#include <wheel/memory/allocator.hpp>

namespace wheel {

namespace detail {

class StringBase {
 public:
  StringBase(char* data, SizeType size, SizeType capacity, IAllocator* allocator) noexcept;

  StringBase(StringBase&& other) noexcept;
  StringBase& operator=(StringBase&& other) noexcept;

 protected:
  ~StringBase() noexcept;

  void Swap(StringBase& other) noexcept;

 protected:
  char* data_;
  SizeType size_;
  SizeType capacity_;
  IAllocator* allocator_;
};

}  // namespace detail

}  // namespace wheel