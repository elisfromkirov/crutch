#include <crutch/memory/detail/raw_ptr_base.hpp>

namespace crutch {

namespace detail {

RawPtrBase::RawPtrBase(Byte* pointer, IAllocator* allocator, SizeType bytes) noexcept
    : pointer_{pointer},
      allocator_{allocator},
      bytes_{bytes} {
}

RawPtrBase::RawPtrBase(RawPtrBase&& other) noexcept
    : RawPtrBase{other.pointer_, other.allocator_, other.bytes_} {
  other.pointer_ = nullptr;
}

RawPtrBase& RawPtrBase::operator=(RawPtrBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  RawPtrBase tmp{::std::move(other)};
  Swap(tmp);

  return *this;
}

RawPtrBase::~RawPtrBase() noexcept {
  if (pointer_ != nullptr) {
    allocator_->Deallocate(pointer_, bytes_);
  }
}

void RawPtrBase::Swap(RawPtrBase& other) noexcept {
  ::std::swap(pointer_, other.pointer_);
  ::std::swap(allocator_, other.allocator_);
  ::std::swap(bytes_, other.bytes_);
}

}  // namespace detail

}  // namespace crutch