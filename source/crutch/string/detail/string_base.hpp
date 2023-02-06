#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

namespace crutch {

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

}  // namespace crutch