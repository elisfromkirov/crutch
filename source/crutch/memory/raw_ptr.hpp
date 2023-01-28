#pragma once

#include <crutch/core/core.hpp>

#include <crutch/memory/allocator.hpp>

#include <crutch/memory/detail/raw_ptr_base.hpp>

namespace crutch {

class RawPtr final : private detail::RawPtrBase {
 public:
  RawPtr(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept;

  [[nodiscard]]
  Byte* Get() const noexcept;

  void Release() noexcept;
};

}  // namespace crutch