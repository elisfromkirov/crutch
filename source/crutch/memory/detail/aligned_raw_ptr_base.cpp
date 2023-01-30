#include <crutch/memory/detail/aligned_raw_ptr_base.hpp>

namespace crutch {

namespace detail {

AlignedRawPtrBase::AlignedRawPtrBase(Byte* pointer, IAllocator* allocator, SizeType bytes, SizeType alignment) noexcept
    : pointer_{pointer},
      allocator_{allocator},
      bytes_{bytes},
      alignment_{alignment} {
}

AlignedRawPtrBase::AlignedRawPtrBase(AlignedRawPtrBase&& other) noexcept
    : AlignedRawPtrBase{other.pointer_, other.allocator_, other.bytes_, other.alignment_} {
  other.pointer_ = nullptr;
}

AlignedRawPtrBase& AlignedRawPtrBase::operator=(AlignedRawPtrBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  AlignedRawPtrBase tmp{::std::move(other)};
  Swap(tmp);

  return *this;
}

AlignedRawPtrBase::~AlignedRawPtrBase() noexcept {
  if (pointer_ != nullptr) {
    allocator_->Deallocate(pointer_, bytes_, alignment_);
  }
}

void AlignedRawPtrBase::Swap(AlignedRawPtrBase& other) noexcept {
  ::std::swap(pointer_, other.pointer_);
  ::std::swap(allocator_, other.allocator_);
  ::std::swap(bytes_, other.bytes_);
  ::std::swap(alignment_, other.alignment_);
}

}  // namespace detail

}  // namespace crutch