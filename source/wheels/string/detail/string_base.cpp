#include <wheels/string/detail/string_base.hpp>

namespace wheels {

namespace detail {

StringBase::StringBase(char* data, SizeType size, SizeType capacity, IAllocator* allocator) noexcept
    : data_{data},
      size_{size},
      capacity_{capacity},
      allocator_{allocator} {
}

StringBase::StringBase(StringBase&& other) noexcept
    : data_{other.data_},
      size_{other.size_},
      capacity_{other.capacity_},
      allocator_{other.allocator_} {
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

StringBase& StringBase::operator=(StringBase&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  StringBase tmp{::std::move(other)};
  Swap(tmp);

  return *this;
}

StringBase::~StringBase() noexcept {
  allocator_->Deallocate(data_, capacity_, kMaxAlignment);
}

void StringBase::Swap(StringBase& other) noexcept {
  ::std::swap(data_, other.data_);
  ::std::swap(size_, other.size_);
  ::std::swap(capacity_, other.capacity_);
  ::std::swap(allocator_, other.allocator_);
}

}  // namespace detail

}  // namespace wheels