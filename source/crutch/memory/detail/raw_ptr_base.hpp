#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

namespace crutch {

namespace detail {

class RawPtrBase {
 public:
  RawPtrBase(Byte* pointer, IAllocator* allocator, SizeType bytes) noexcept;

  RawPtrBase(const RawPtrBase& other) = delete;
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
};

}  // namespace detail

}  // namespace crutch