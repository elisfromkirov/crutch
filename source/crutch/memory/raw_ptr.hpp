#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

#include <crutch/memory/detail/raw_ptr_base.hpp>

namespace crutch {

template <typename Type>
class RawPtr final : private detail::RawPtrBase<Type> {
 public:
  RawPtr(Type* pointer, IAllocator* allocator) noexcept;

  [[nodiscard]]
  Type* Get() const noexcept;

  void Release() noexcept;
};

}  // namespace crutch

#define RAW_PTR_IMPL
#include <crutch/memory/raw_ptr.ipp>
#undef RAW_PTR_IMPL