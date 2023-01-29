#pragma once

#include <crutch/core/type/size.hpp>

#include <crutch/allocator/core/allocator.hpp>

#include <crutch/memory/raw/detail/raw_ptr_base.hpp>

namespace crutch {

class RawPtr final : private detail::RawPtrBase {
 public:
  RawPtr(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept;

  [[nodiscard]]
  Byte* Get() const noexcept;

  void Release() noexcept;
};

}  // namespace crutch