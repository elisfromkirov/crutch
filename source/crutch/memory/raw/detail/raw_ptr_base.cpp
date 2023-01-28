#include "crutch/memory/raw/detail/raw_ptr_base.hpp"

namespace crutch {

namespace detail {

RawPtrBase::RawPtrBase(Byte* pointer, IAllocator* allocator, SizeType bytes,
                       SizeType alignment) noexcept
    : pointer_{pointer},
      allocator_{allocator},
      bytes_{bytes},
      alignment_{alignment} {
}

RawPtrBase::RawPtrBase(RawPtrBase&& other) noexcept
    : RawPtrBase{other.pointer_, other.allocator_, other.bytes_, other.alignment_} {
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
  allocator_->Deallocate(pointer_, bytes_, alignment_);
}

void RawPtrBase::Swap(RawPtrBase& other) noexcept {
}

}  // namespace detail

}  // namespace crutch