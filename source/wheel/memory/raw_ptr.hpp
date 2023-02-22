#pragma once

#include <wheel/core/core.hpp>

#include <wheel/memory/allocator.hpp>

#include <wheel/memory/detail/raw_ptr_base.hpp>

namespace wheel {

template <typename Type>
class RawPtr final : private detail::RawPtrBase<Type> {
 public:
  RawPtr(Type* pointer, IAllocator* allocator) noexcept;

  [[nodiscard]]
  Type* Get() const noexcept;

  void Release() noexcept;
};

}  // namespace wheel

#define RAW_PTR_IMPL
#include <wheel/memory/raw_ptr.ipp>
#undef RAW_PTR_IMPL