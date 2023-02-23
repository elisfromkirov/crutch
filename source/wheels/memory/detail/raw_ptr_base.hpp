#pragma once

#include <wheels/core/core.hpp>

#include <wheels/memory/allocator.hpp>

namespace wheels {

namespace detail {

template <typename Type>
class RawPtrBase {
 public:
  RawPtrBase(Type* pointer, IAllocator* allocator) noexcept;

  RawPtrBase(const RawPtrBase& other) = delete;
  RawPtrBase& operator=(const RawPtrBase& other) = delete;

  RawPtrBase(RawPtrBase&& other) noexcept;
  RawPtrBase& operator=(RawPtrBase&& other) noexcept;

 protected:
  ~RawPtrBase() noexcept;

  void Swap(RawPtrBase& other) noexcept;

 protected:
  Type* pointer_;
  IAllocator* allocator_;
};

}  // namespace detail

}  // namespace wheels

#define RAW_PTR_BASE_IMPL
#include <wheels/memory/detail/raw_ptr_base.ipp>
#undef RAW_PTR_BASE_IMPL