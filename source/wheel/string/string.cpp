#include <wheel/string/string.hpp>

namespace wheel {

char& String::operator[](SizeType index) noexcept {
  ASSERT(IsValid(), "string is invalid");
  ASSERT(index < size_, "index must be less than size");

  return data_[index];
}

const char& String::operator[](SizeType index) const noexcept {
  ASSERT(IsValid(), "string is invalid");
  ASSERT(index < size_, "index must be less than size");

  return data_[index];
}

char& String::At(SizeType index) noexcept {
  ASSERT(IsValid(), "string is invalid");
  ASSERT(index < size_, "index must be less than size");

  return data_[index];
}

const char& String::At(SizeType index) const noexcept {
  ASSERT(IsValid(), "string is invalid");
  ASSERT(index < size_, "index must be less than size");

  return data_[index];
}

char* String::Data() noexcept {
  ASSERT(IsValid(), "string is invalid");

  return data_;
}

const char* String::Data() const noexcept {
  ASSERT(IsValid(), "string is invalid");

  return data_;
}

SizeType String::Size() const noexcept {
  ASSERT(IsValid(), "string is invalid");

  return size_;
}

SizeType String::Capacity() const noexcept {
  ASSERT(IsValid(), "string is invalid");

  return capacity_;
}

StringView String::View() const noexcept {
  ASSERT(IsValid(), "string is invalid");

  return StringView{data_, size_};
}

String::String(char* data, SizeType size, SizeType capacity, IAllocator* allocator) noexcept
    : detail::StringBase{data, size, capacity, allocator} {
}

bool String::IsValid() const noexcept {
  return data_ != nullptr && size_ < capacity_ && capacity_ != 0 && allocator_ != nullptr;
}

bool operator==(const String& lhs, const String& rhs) noexcept {
  return ::std::strcmp(lhs.Data(), rhs.Data()) == 0;
}

}  // namespace wheel