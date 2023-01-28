#pragma once

#include "crutch/core/core.hpp"

#include "crutch/allocator/core/allocator.hpp"

namespace crutch {

namespace detail {

class RawPtrBase {
 public:
  RawPtrBase(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept;

  RawPtrBase(const RawPtrBase& other) = delete;
  RawPtrBase(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment);
  RawPtrBase& operator=(const RawPtrBase& other) = delete;

  RawPtrBase(RawPtrBase&& other) noexcept;
  RawPtrBase& operator=(RawPtrBase&& other) noexcept;

 protected:
  ~RawPtrBase() noexcept;

 protected:
  void Swap(RawPtrBase& other) noexcept;

 protected:
  Byte* pointer_;
  IAllocator* allocator_;
  SizeType bytes_;
  SizeType alignment_;
};

}  // namespace detail

}  // namespace crutch