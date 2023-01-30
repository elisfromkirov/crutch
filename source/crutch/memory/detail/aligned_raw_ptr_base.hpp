#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

namespace crutch {

namespace detail {

class AlignedRawPtrBase {
 public:
  AlignedRawPtrBase(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept;

  AlignedRawPtrBase(const AlignedRawPtrBase& other) = delete;
  AlignedRawPtrBase& operator=(const AlignedRawPtrBase& other) = delete;

  AlignedRawPtrBase(AlignedRawPtrBase&& other) noexcept;
  AlignedRawPtrBase& operator=(AlignedRawPtrBase&& other) noexcept;

 protected:
  ~AlignedRawPtrBase() noexcept;

 protected:
  void Swap(AlignedRawPtrBase& other) noexcept;

 protected:
  Byte* pointer_;
  IAllocator* allocator_;
  SizeType bytes_;
  SizeType alignment_;
};

}  // namespace detail

}  // namespace crutch