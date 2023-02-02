#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

namespace crutch {

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

}  // namespace crutch

#define RAW_PTR_BASE_IMPL
#include <crutch/memory/detail/raw_ptr_base.ipp>
#undef RAW_PTR_BASE_IMPL