#pragma once

#include <crutch/allocator/core/allocator.hpp>

#include <crutch/core/type/size.hpp>

#include <utility>

namespace crutch {

namespace detail {

class RawPtrBase {
 public:
  RawPtrBase(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept;

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
  SizeType alignment_;
};

}  // namespace detail

}  // namespace crutch