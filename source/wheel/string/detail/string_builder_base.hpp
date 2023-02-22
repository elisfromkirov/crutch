#pragma once

#include <wheel/core/core.hpp>

#include <wheel/memory/allocator.hpp>

namespace wheel {

namespace detail {

class StringBuilderBase {
 public:
  StringBuilderBase(SizeType capacity, IAllocator* allocator);

  StringBuilderBase(char* data, SizeType size, SizeType capacity, IAllocator* allocator);

 protected:
  ~StringBuilderBase() noexcept;

  void Swap(StringBuilderBase& other) noexcept;

 protected:
  char* data_;
  SizeType size_;
  SizeType capacity_;
  IAllocator* allocator_;
};

}  // namespace detail

}  // namespace wheel