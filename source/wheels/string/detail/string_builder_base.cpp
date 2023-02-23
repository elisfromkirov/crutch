#include <wheels/string/detail/string_builder_base.hpp>

namespace wheels {

namespace detail {

StringBuilderBase::StringBuilderBase(SizeType capacity, IAllocator* allocator)
    : data_{static_cast<char*>(allocator->Allocate(capacity, kMaxAlignment))},
      size_{0},
      capacity_{capacity},
      allocator_{allocator} {
}

StringBuilderBase::StringBuilderBase(char* data, SizeType size, SizeType capacity, IAllocator* allocator)
    : data_{data},
      size_{size},
      capacity_{capacity},
      allocator_{allocator} {
}

StringBuilderBase::~StringBuilderBase() noexcept {
  allocator_->Deallocate(data_, capacity_, kMaxAlignment);
}

void StringBuilderBase::Swap(StringBuilderBase& other) noexcept {
  ::std::swap(data_, other.data_);
  ::std::swap(size_, other.size_);
  ::std::swap(capacity_, other.capacity_);
  ::std::swap(allocator_, other.allocator_);
}

}  // namespace detail

}  // namespace wheels