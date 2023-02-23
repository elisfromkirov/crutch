#pragma once

#include <wheels/core/core.hpp>

#include <wheels/memory/allocator.hpp>

#include <wheels/memory/detail/raw_ptr_base.hpp>

namespace wheels {

template <typename Type>
class RawPtr final : private detail::RawPtrBase<Type> {
 public:
  RawPtr(Type* pointer, IAllocator* allocator) noexcept;

  [[nodiscard]]
  Type* Get() const noexcept;

  void Release() noexcept;
};

}  // namespace wheels

#define RAW_PTR_IMPL
#include <wheels/memory/raw_ptr.ipp>
#undef RAW_PTR_IMPL