#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

namespace crutch {

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

}  // namespace crutch