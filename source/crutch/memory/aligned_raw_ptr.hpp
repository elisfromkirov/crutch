#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

#include <crutch/memory/detail/aligned_raw_ptr_base.hpp>

namespace crutch {

class AlignedRawPtr final : private detail::AlignedRawPtrBase {
 public:
  AlignedRawPtr(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept;

  [[nodiscard]]
  Byte* Get() const noexcept;

  void Release() noexcept;
};

}  // namespace crutch